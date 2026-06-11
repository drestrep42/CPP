#include "PmergeMe.hpp"
#include <sstream>
#include <vector>

void printDeque(const std::deque<int>& nbrs, bool sorted)
{
	if (!sorted)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (size_t i = 0; i < nbrs.size(); ++i)
	{
		std::cout << nbrs[i];
		if (i != nbrs.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void relabelGroupAsPair(GroupNode& group, int pairIndex)
{
	// Las etiquetas se asignan por nivel de recursión,
	// así que se limpian las etiquetas anteriores antes de asignar el nuevo par.
	for (size_t i = 0; i < group.values.size(); ++i)
		group.values[i].label.clear();

	if (group.values.size() < 2)
		return;

	const size_t halfSize = group.values.size() / 2;
	std::ostringstream bLabel;
	bLabel << 'b' << pairIndex;
	std::ostringstream aLabel;
	aLabel << 'a' << pairIndex;
	group.values[halfSize - 1].label = bLabel.str();
	group.values.back().label = aLabel.str();
}

// Limpia las etiquetas de un grupo para que no interfieran con el etiquetado de niveles posteriores.
static void clearGroupLabels(GroupNode& group)
{
	for (size_t i = 0; i < group.values.size(); ++i)
		group.values[i].label.clear();
}

// Si un grupo queda sin pareja, se etiqueta como bN para que se inserte después de aN en el orden de Jacobsthal.
static void labelUnpairedGroupAsB(GroupNode& group, int pairIndex)
{
	clearGroupLabels(group);
	if (group.values.empty())
		return;

	std::ostringstream label;
	label << 'b' << pairIndex;
	group.values.back().label = label.str();
}

static void sortGroup(GroupNode& group, int level, int pairIndex)
{
	// Cada grupo representa una secuencia ya partida en dos mitades del mismo tamaño.
	// Ejemplo: si el grupo es [3 8 1 5] en level 2, se compara [3 8] con [1 5].
	// El código compara los últimos elementos de cada mitad: 8 contra 5.
	// Si el último elemento de la mitad izquierda es mayor, se intercambian las mitades.
	if (group.values.size() < 2)
		return;

	// El tamaño esperado de cada mitad se calcula como 2^(level-1) porque cada nivel duplica el tamaño del grupo.
	// Por ejemplo, en level 3, el tamaño esperado de cada mitad es 2^(3-1) = 4, 
	// lo que significa que el grupo completo debería tener al menos 8 elementos para poder dividirse en dos mitades de 4.
	const size_t childSize = static_cast<size_t>(std::pow(2, level - 1));
	if (group.values.size() < childSize * 2)
		return;

	// Se crean las mitades izquierda y derecha a partir del grupo actual.
	// En el ejemplo, left sería [3 8] y right sería [1 5]. Luego se compara el último elemento de cada mitad.
	std::deque<Element> left(group.values.begin(), group.values.begin() + childSize);
	std::deque<Element> right(group.values.begin() + childSize, group.values.begin() + childSize * 2);

	// Si el último elemento de la mitad izquierda es mayor que el último de la derecha, se intercambian las mitades.
	if (!left.empty() && !right.empty() && left.back().value > right.back().value)
	{
		std::deque<Element> swapped;
		swapped.insert(swapped.end(), right.begin(), right.end());
		swapped.insert(swapped.end(), left.begin(), left.end());
		group.values = swapped;
	}
	// Después de ordenar el grupo, se actualiza su clave al último elemento del grupo, que es el mayor.
	// En el ejemplo, después de ordenar [3 8 1 5] a [1 5 3 8], la clave se actualiza a 8.
	group.key = group.values.back().value;

	// Reetiqueta elementos en el par:
	// la primera mitad es b (más pequeña), la segunda mitad es a (más grande)
	relabelGroupAsPair(group, pairIndex);
}

static void splitMainPend(const GroupList& currentGroups, size_t expectedSize,
					  GroupList& relabeledCurrent,
					  GroupList& mainGroups,
					  GroupList& pendGroups,
					  GroupList& nonParticipating)
{
	// El siguiente ciclo for aplana la secuencia de grupos en 
	// una secuencia plana de elementos para luego reconstruir 
	//los grupos de este nivel con el tamaño esperado.
	std::deque<Element> flat;
	for (size_t g = 0; g < currentGroups.size(); ++g)
	{
		for (size_t v = 0; v < currentGroups[g].values.size(); ++v)
			flat.push_back(Element(currentGroups[g].values[v].value, ""));
	}

	// Construye los grupos de este nivel a partir de la secuencia plana, 
	// tomando bloques de tamaño esperado.
	size_t pos = 0;
	while (pos + expectedSize <= flat.size())
	{
		GroupNode node;
		node.values.insert(node.values.end(), flat.begin() + pos, flat.begin() + pos + expectedSize);
		node.key = node.values.back().value;
		relabeledCurrent.push_back(node);
		pos += expectedSize;
	}

	// Los elementos restantes que no alcanzan a formar un grupo completo 
	// se clasifican como no participantes y se guardan aparte 
	// para ser añadidos al final de la secuencia final.
	if (pos < flat.size())
	{
		GroupNode remainder;
		remainder.values.insert(remainder.values.end(), flat.begin() + pos, flat.end());
		remainder.key = remainder.values.back().value;
		nonParticipating.push_back(remainder);
	}

	// Reetiqueta por nivel: (b1,a1), (b2,a2), ... y posible bN final.
	// Esto se hace para marcar el rol de cada grupo en la inserción.
	int pairIndex = 1;
	for (size_t i = 0; i < relabeledCurrent.size(); i += 2)
	{
		clearGroupLabels(relabeledCurrent[i]);
		if (!relabeledCurrent[i].values.empty())
		{
			std::ostringstream bLabel;
			bLabel << 'b' << pairIndex;
			relabeledCurrent[i].values.back().label = bLabel.str();
		}

		if (i + 1 < relabeledCurrent.size())
		{
			clearGroupLabels(relabeledCurrent[i + 1]);
			if (!relabeledCurrent[i + 1].values.empty())
			{
				std::ostringstream aLabel;
				aLabel << 'a' << pairIndex;
				relabeledCurrent[i + 1].values.back().label = aLabel.str();
			}
		}
		++pairIndex;
	}

	if (relabeledCurrent.empty())
		return;

	// Main empieza con {b1, a1} cuando a1 existe, luego todas las a restantes.
	mainGroups.push_back(relabeledCurrent[0]);
	if (relabeledCurrent.size() > 1)
		mainGroups.push_back(relabeledCurrent[1]);

	// Pend empieza con b2 si existe, luego todas las b restantes.
	for (size_t i = 2; i < relabeledCurrent.size(); ++i)
	{
		if (!relabeledCurrent[i].values.empty() && !relabeledCurrent[i].values.back().label.empty()
			&& relabeledCurrent[i].values.back().label[0] == 'a')
			mainGroups.push_back(relabeledCurrent[i]);
		else
			pendGroups.push_back(relabeledCurrent[i]);
	}
}

static GroupNode combineGroups(const GroupNode& left, const GroupNode& right)
{
	// Une dos grupos contiguos preservando el orden original de sus elementos.
	GroupNode parent;
	parent.values = left.values;
	parent.values.insert(parent.values.end(), right.values.begin(), right.values.end());
	parent.key = parent.values.back().value;
	return parent;
}

GroupList operator+(const GroupList& first, const GroupList& second)
{
	GroupList combined = first;
	combined.insert(combined.end(), second.begin(), second.end());
	return combined;
}

// Dado un grupo pend, encuentra la posición donde debería insertarse en la cadena principal actual.
static int getGroupLabelIndex(const GroupNode& group)
{

	// La etiqueta identifica a qué par pertenece este grupo en el nivel actual. 
	// Usamos el sufijo numérico para saber contra qué límite de main-group debe 
	// compararse el grupo pend antes de insertarlo.
	if (group.values.empty() || group.values.back().label.size() < 2)
		return -1;
	const std::string& label = group.values.back().label;

	if (label[0] != 'a' && label[0] != 'b')
		return -1;
	int index = 0;
	for (size_t i = 1; i < label.size(); ++i)
	{
		// Parsea el sufijo numérico de la etiqueta para obtener el índice 
		// del par al que pertenece este grupo pend.
		if (label[i] < '0' || label[i] > '9')
			return -1;
		index = index * 10 + (label[i] - '0');
	}
	return index;
}

static size_t findBoundedInsertionPoint(const GroupList& mainGroups, const GroupNode& pendGroup)
{

	// Esta función encuentra la posición donde se debe insertar un grupo pend en la cadena principal actual.
	// Primero, se limita la búsqueda a la porción permitida por la etiqueta aN correspondiente, 
	// luego se compara solo contra el valor más grande de cada grupo.
	const int pendIndex = getGroupLabelIndex(pendGroup);
	const int boundIndex = pendIndex > 0 ? pendIndex : -1;
	size_t searchLimit = mainGroups.size();

	if (boundIndex > 0)
	{
		for (size_t i = 0; i < mainGroups.size(); ++i)
		{
			// Compara las etiquetas para detenerse en el elemento aN correspondiente. 
			// Ese es el límite superior del área de búsqueda de este grupo pend.
			if (getGroupLabelIndex(mainGroups[i]) == boundIndex)
			{
				searchLimit = i + 1;
				break;
			}
		}
	}

	// Dentro del área de búsqueda limitada, se compara 
	// el valor más grande del grupo pend contra el valor más grande de cada grupo main.
	const int pendKey = pendGroup.values.empty() ? 0 : pendGroup.values.back().value;
	for (size_t i = 0; i < searchLimit; ++i)
	{
		if (!mainGroups[i].values.empty()
			&& mainGroups[i].values.back().value > pendKey)
			// Se inserta el grupo pend antes del primer grupo main que tenga un valor más grande.
			return i;
	}
	// Si no se encuentra ningún grupo main con un valor más grande dentro del área de búsqueda,
	// se inserta el grupo pend al final de esa área.
	return searchLimit;
}

// Implementa la inserción de los elementos de pendGroups en mainGroups siguiendo el orden de Jacobsthal.
// Empieza con Jacobsthal número 3 (dos inserciones)
// Luego Jacobsthal número 5 (tres inserciones)
// Luego Jacobsthal número 11 (seis inserciones)
// Etc
static GroupList JacobsthalInsertion(GroupList mainGroups, GroupList pendGroups)
{
	if (pendGroups.empty())
		return mainGroups;

	// Primero, encontramos el índice máximo de etiqueta entre los grupos
	// pend para saber hasta dónde llegar con los números de Jacobsthal.
	int maxIndex = 0;
	for (size_t i = 0; i < pendGroups.size(); ++i)
	{
		const int index = getGroupLabelIndex(pendGroups[i]);
		if (index > maxIndex)
			maxIndex = index;
	}

	// Iteramos explícitamente por bloques de números de Jacobsthal para insertar (current - previous)
	// elementos pend por cada bloque de número de Jacobsthal.
	// Esto asegura que para j=3 insertamos 2 elementos (3 - 1): b3 luego b2.
	int previous = 1;
	int current = 3;
	while (previous < maxIndex && !pendGroups.empty())
	{
		const int blockTop = (current < maxIndex) ? current : maxIndex;
		// Inserta índices desde blockTop hasta previous+1 (incluídos).
		for (int idx = blockTop; idx > previous && !pendGroups.empty(); --idx)
		{
			// Localiza el grupo bN seleccionado por este índice de Jacobsthal.
			// Si no existe, se salta al siguiente índice.
			size_t pendPos = pendGroups.size();
			for (size_t i = 0; i < pendGroups.size(); ++i)
			{
				if (getGroupLabelIndex(pendGroups[i]) == idx)
				{
					pendPos = i;
					break;
				}
			}
			if (pendPos == pendGroups.size())
				continue;

			const GroupNode currentPend = pendGroups[pendPos];
			
			// Compara el grupo pend actual contra la cadena principal limitada por su etiqueta aN para decidir dónde insertarlo.
			const size_t insertPos = findBoundedInsertionPoint(mainGroups, currentPend);
			mainGroups.insert(mainGroups.begin() + insertPos, currentPend);
			pendGroups.erase(pendGroups.begin() + pendPos);
		}

		// Avanza al siguiente bloque de números de Jacobsthal.
		const int next = current + 2 * previous;
		previous = current;
		current = next;
	}

	return mainGroups;
}

static GroupList insertion(const GroupList& currentGroups, int level)
{
	const size_t expectedSize = static_cast<size_t>(std::pow(2, level - 1));
	
	GroupList relabeledCurrent;
	GroupList mainGroups;
	GroupList pendGroups;
	GroupList nonParticipating;

	// Dividimos la secuencia actual en grupos de tamaño esperado y 
	// los reetiquetamos para marcar sus roles en la inserción.
	splitMainPend(currentGroups, expectedSize, relabeledCurrent, mainGroups, pendGroups, nonParticipating);

	// Si hay grupos pend, se insertan en main siguiendo el orden de Jacobsthal.
	GroupList mergedMain;
	if (!pendGroups.empty())
		mergedMain = JacobsthalInsertion(mainGroups, pendGroups);
	else
		mergedMain = mainGroups;

	// Construye la secuencia final de este nivel: 
	// primero la cadena principal con los pend insertados, 
	// luego los grupos no participantes al final.
	GroupList finalSequence = mergedMain;
	for (size_t i = 0; i < nonParticipating.size(); ++i)
		finalSequence.push_back(nonParticipating[i]);

	return finalSequence;
}


// Aplana la secuencia de grupos resultante en una secuencia plana de enteros para devolver el resultado final.
static std::deque<int> flattenGroupList(const GroupList& groups)
{
	std::deque<int> flattened;
	for (size_t g = 0; g < groups.size(); ++g)
	{
		for (size_t v = 0; v < groups[g].values.size(); ++v)
			flattened.push_back(groups[g].values[v].value);
	}
	return flattened;
}

static GroupList recurseGroups(const GroupList& currentGroups, const GroupList& currentPend, int level, size_t totalSize)
{
	// Cuando el tamaño objetivo ya no cabe en el total, o queda un solo grupo, terminamos.
	if (static_cast<size_t>(std::pow(2, level)) > totalSize || currentGroups.size() < 2)
		return currentGroups;
	
	// Tamaño esperado de cada grupo en este nivel. 
	// Para level 2, cada grupo tendrá 2^(2-1) = 2 elementos.
	const size_t expectedSize = static_cast<size_t>(std::pow(2, level - 1));

	GroupList nextGroups;
	GroupList unpairedGroups;

	// Agrupamos de dos en dos solo si ambos grupos tienen el tamaño esperado.
	size_t i = 0;
	while (i + 1 < currentGroups.size())
	{
		if (currentGroups[i].values.size() != expectedSize
			|| currentGroups[i + 1].values.size() != expectedSize)
			break;

		nextGroups.push_back(combineGroups(currentGroups[i], currentGroups[i + 1])); // Combina los grupos contiguos en un nuevo grupo padre.
		i += 2;
	}

	// Si sobra un grupo del nivel actual, sigue formando parte del nivel actual
	// pero no se compara porque ya no tiene pareja.
	for (; i < currentGroups.size(); ++i)
	{
		GroupNode leftover = currentGroups[i];
		labelUnpairedGroupAsB(leftover, static_cast<int>(nextGroups.size() + unpairedGroups.size() + 1));
		unpairedGroups.push_back(leftover);
	}

	GroupList currentLevelGroups = nextGroups + unpairedGroups;
	GroupList visiblePend;
	for (size_t i = 0; i < currentPend.size(); ++i)
	{
		if (currentPend[i].values.size() < expectedSize)
			visiblePend.push_back(currentPend[i]);
	}

	// Ordenamos cada grupo combinado según la regla de Ford-Johnson.
	for (size_t i = 0; i < nextGroups.size(); ++i)
		sortGroup(nextGroups[i], level, static_cast<int>(i) + 1);

	currentLevelGroups = nextGroups + unpairedGroups;

	// El siguiente nivel usa los grupos ya combinados más los pend sin tocar.
	GroupList childResult = recurseGroups(currentLevelGroups, visiblePend, level + 1, totalSize);


	// Usamos el resultado de la recursión (la secuencia producida por el nivel más profundo)
	// como la secuencia actual con la que trabajar en este nivel, luego se añaden los pend visibles.
	GroupList debugCurrent = childResult + visiblePend;
	GroupList merged = insertion(debugCurrent, level);

	// Devuelve la secuencia resultante de este nivel, que se usará como base para el siguiente nivel de recursión.
	return merged;
}

// Construye la lista inicial de grupos a partir de la secuencia de números dada,
// donde cada grupo es un singleton con un número y su clave es ese mismo número.
static GroupList buildInitialGroups(std::deque<int>::iterator begin,
								  std::deque<int>::iterator end)
{
	GroupList groups;

	for (std::deque<int>::iterator it = begin; it != end; ++it)
	{
		GroupNode node;
		node.values.push_back(Element(*it, ""));
		node.key = *it;
		groups.push_back(node);
	}
	return groups;
}

void FordJohnson(std::deque<int>& nbrs)
{
	if (nbrs.empty())
	{
		nbrs.clear();
		return;
	}
	GroupList currentGroups = buildInitialGroups(nbrs.begin(), nbrs.end());
	GroupList finalGroups = recurseGroups(currentGroups, GroupList(), 1, static_cast<size_t>(nbrs.end() - nbrs.begin()));
	nbrs = flattenGroupList(finalGroups);
}
