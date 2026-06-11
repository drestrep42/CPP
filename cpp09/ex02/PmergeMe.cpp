#include "PmergeMe.hpp"
#include <sstream>
#include <vector>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **begin, char **end)
{
	for (char **it = begin; it != end; ++it)
	{
		int nbr = std::atoi(*it);
		if (nbr < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		_nbrs.push_back(nbr);
	}
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
		this->_nbrs = other._nbrs;
	return *this;
}

void PmergeMe::print(bool sorted) const
{
	// Imprime el contenido actual de la estructura con una etiqueta que indica si
	// todavía representa el estado inicial o el resultado final ya ordenado.
	if (!sorted)
		std::cout << "Before: ";
	else
		std::cout << "After: ";
	for (size_t i = 0; i < _nbrs.size(); ++i)
	{
		std::cout << _nbrs[i];
		if (i != _nbrs.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void relabelGroupAsPair(GroupNode& group, int pairIndex)
{
	// Labels are scoped to the current recursion level, so clear any previous
	// labels before assigning the new pair labels.
	for (size_t i = 0; i < group.values.size(); ++i)
		group.values[i].label.clear();

	// Relabel only the representative element of each half.
	// For level 1 the halves are singletons, so both elements get labels.
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

static void clearGroupLabels(GroupNode& group)
{
	for (size_t i = 0; i < group.values.size(); ++i)
		group.values[i].label.clear();
}

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
	//En el ejemplo, después de ordenar [3 8 1 5] a [1 5 3 8], la clave se actualiza a 8.
	group.key = group.values.back().value;

	// Relabel elements in the pair: first half is b (smaller), second half is a (larger)
	relabelGroupAsPair(group, pairIndex);
}

static void printValues(const std::deque<Element>& values)
{
	// Imprime una secuencia plana separando sus elementos por espacios.
	for (size_t i = 0; i < values.size(); ++i)
	{
		std::cout << values[i].value;
		if (!values[i].label.empty())
			std::cout << "[" << values[i].label << "]";
		if (i + 1 != values.size())
			std::cout << " ";
	}
}

static void printGroup(const std::deque<Element>& values, int level, bool levelOneNestedSingles)
{
	// Reconstuye visualmente un grupo con paréntesis anidados para que se vea
	// cómo los números se van agrupando por niveles en el algoritmo.
	std::cout << "(";
	if (level <= 1)
	{
		if (levelOneNestedSingles && values.size() == 2)
		{
			std::cout << "(" << values[0].value;
			if (!values[0].label.empty())
				std::cout << "[" << values[0].label << "]";
			std::cout << ") (" << values[1].value;
			if (!values[1].label.empty())
				std::cout << "[" << values[1].label << "]";
			std::cout << ")";
		}
		else
			printValues(values);
	}
	else
	{
		const size_t childSize = static_cast<size_t>(std::pow(2, level - 1));
		if (values.size() < childSize || (values.size() % childSize) != 0)
			printValues(values);
		else
			for (size_t i = 0; i < values.size(); i += childSize)
		{
			std::deque<Element> child(values.begin() + i, values.begin() + i + childSize);
			printGroup(child, level - 1, false);
			if (i + childSize < values.size())
				std::cout << " ";
		}
	}
	std::cout << ")";
}

/* static int levelFromSize(size_t size)
{
	// Calcula el nivel mínimo necesario para representar una secuencia de ese tamaño.
	int level = 1;
	while ((static_cast<size_t>(std::pow(2, level))) < size)
		++level;
	return level;
} */

/* static void printGroupList(const GroupList& groups,
					   const GroupList& tails,
					   int level)
{
	// Imprime primero los grupos activos del nivel actual y luego los tails que
	// no pudieron emparejarse pero siguen formando parte del estado visible.
	for (size_t i = 0; i < groups.size(); ++i)
	{
		printGroup(groups[i].values, level, level == 1);
		if (i + 1 < groups.size() || !tails.empty())
			std::cout << " ";
	}
	for (size_t i = 0; i < tails.size(); ++i)
	{
		printGroup(tails[i].values, levelFromSize(tails[i].values.size()), false);
		if (i + 1 < tails.size())
			std::cout << " ";
	}
} */

/* static void printRecursionStep(const char* label, int level,
							   const GroupList& groups, const GroupList& tails)
{
	// Label es "Before" o "After" para indicar el estado del nivel actual antes y después de ordenar los grupos.
	// Etiqueta un estado intermedio de la recursión para poder comparar el antes y el después.
	std::cout << label << " level " << level << ": ";
	printGroupList(groups, tails, level);
	std::cout << std::endl;
} */

/* static void printGroupListByOwnSize(const GroupList& groups)
{
	for (size_t i = 0; i < groups.size(); ++i)
	{
		printGroup(groups[i].values, levelFromSize(groups[i].values.size()), false);
		if (i + 1 < groups.size())
			std::cout << " ";
	}
} */

static void splitMainPend(const GroupList& currentGroups,
					  size_t expectedSize,
					  GroupList& relabeledCurrent,
					  GroupList& mainGroups,
					  GroupList& pendGroups,
					  GroupList& nonParticipating)
{
	std::deque<Element> flat;
	for (size_t g = 0; g < currentGroups.size(); ++g)
	{
		for (size_t v = 0; v < currentGroups[g].values.size(); ++v)
			flat.push_back(Element(currentGroups[g].values[v].value, ""));
	}

	// Build level elements of exactly expectedSize from the flattened sequence.
	size_t pos = 0;
	while (pos + expectedSize <= flat.size())
	{
		GroupNode node;
		node.values.insert(node.values.end(), flat.begin() + pos, flat.begin() + pos + expectedSize);
		node.key = node.values.back().value;
		relabeledCurrent.push_back(node);
		pos += expectedSize;
	}

	// Remaining elements are non-participating at this level.
	if (pos < flat.size())
	{
		GroupNode remainder;
		remainder.values.insert(remainder.values.end(), flat.begin() + pos, flat.end());
		remainder.key = remainder.values.back().value;
		nonParticipating.push_back(remainder);
	}

	// Relabel current per level: (b1,a1), (b2,a2), ... and possible trailing bN.
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

	// Main starts with {b1, a1} when a1 exists, then all remaining a's.
	mainGroups.push_back(relabeledCurrent[0]);
	if (relabeledCurrent.size() > 1)
		mainGroups.push_back(relabeledCurrent[1]);

	// Pend starts with the remaining b's from b2.
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

static int getGroupLabelIndex(const GroupNode& group)
{
	// The label identifies which pair this group belongs to at the current level.
	// We use the numeric suffix to know which main-group boundary the pend group
	// should be compared against before inserting.
	if (group.values.empty() || group.values.back().label.size() < 2)
		return -1;
	const std::string& label = group.values.back().label;
	// Only labels of the form aN or bN are meaningful here.
	if (label[0] != 'a' && label[0] != 'b')
		return -1;
	int index = 0;
	for (size_t i = 1; i < label.size(); ++i)
	{
		// Parse the numeric suffix one digit at a time so we can match
		// the pend group to its partner in the main chain.
		if (label[i] < '0' || label[i] > '9')
			return -1;
		index = index * 10 + (label[i] - '0');
	}
	return index;
}

static size_t findBoundedInsertionPoint(const GroupList& mainGroups,
											 const GroupNode& pendGroup)
{
	// This finds where the whole pend group should go in the current main chain.
	// First we limit the search to the portion allowed by the corresponding aN
	// boundary, then we compare only against each group's largest value.
	const int pendIndex = getGroupLabelIndex(pendGroup);
	const int boundIndex = pendIndex > 0 ? pendIndex : -1;
	size_t searchLimit = mainGroups.size();

	if (boundIndex > 0)
	{
		for (size_t i = 0; i < mainGroups.size(); ++i)
		{
			// Compare labels to stop at the matching aN element. That is the
			// upper bound for the search area of this pend group.
			if (getGroupLabelIndex(mainGroups[i]) == boundIndex)
			{
				searchLimit = i + 1;
				break;
			}
		}
	}

	const int pendKey = pendGroup.values.empty() ? 0 : pendGroup.values.back().value;
	for (size_t i = 0; i < searchLimit; ++i)
	{
		// Compare the pend group's largest value against the largest value of
		// each candidate in the bounded search window.
		if (!mainGroups[i].values.empty()
			&& mainGroups[i].values.back().value > pendKey)
			// Insert before the first group whose maximum is larger.
			return i;
	}
	// If no larger candidate exists, append the pend group at the end of the
	// bounded search window.
	return searchLimit;
}

// Jacobsthal order is iterated directly inside JacobsthalInsertion now.

/* static void printMainPendState(const GroupList& mainGroups, const GroupList& pendGroups)
{
	// Helper used only for debug output around each insertion step.
	std::cout << "main: ";
	printGroupListByOwnSize(mainGroups);
	std::cout << std::endl;
	std::cout << "pend: ";
	printGroupListByOwnSize(pendGroups);
	std::cout << std::endl;
} */

// Implementa la inserción de los elementos de pendGroups en mainGroups siguiendo el orden de Jacobsthal.
// Empieza con Jacobsthal número 3 (dos inserciones)
// Luego Jacobsthal número 5 (tres inserciones)
// Luego Jacobsthal número 11 (seis inserciones)
// Etc
static GroupList JacobsthalInsertion(GroupList mainGroups, GroupList pendGroups, int level)
{
	(void)level;
	// Operate on copies and return the resulting mainGroups so callers can
	// assemble the next-level sequence.
	if (pendGroups.empty())
		return mainGroups;

	//std::cout << std::endl;
	//printMainPendState(mainGroups, pendGroups);

	int maxIndex = 0;
	for (size_t i = 0; i < pendGroups.size(); ++i)
	{
		const int index = getGroupLabelIndex(pendGroups[i]);
		if (index > maxIndex)
			maxIndex = index;
	}

	// Iterate Jacobsthal blocks explicitly so we insert (current - previous)
	// pend elements for each Jacobsthal number block. This ensures for j=3
	// we insert 2 elements (3 - 1): b3 then b2.
	int previous = 1;
	int current = 3;
	while (previous < maxIndex && !pendGroups.empty())
	{
		const int blockTop = (current < maxIndex) ? current : maxIndex;
		// Insert indices from blockTop down to previous+1 (inclusive).
		for (int idx = blockTop; idx > previous && !pendGroups.empty(); --idx)
		{
			// Locate the bN group selected by this Jacobsthal index.
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
				continue; // index not present in pendGroups

			const GroupNode currentPend = pendGroups[pendPos];
			// Compare against the bounded main chain to decide the insertion slot.
			const size_t insertPos = findBoundedInsertionPoint(mainGroups, currentPend);
			mainGroups.insert(mainGroups.begin() + insertPos, currentPend);
			pendGroups.erase(pendGroups.begin() + pendPos);

			// Print the new state after this insertion so the progression is visible.
			//printMainPendState(mainGroups, pendGroups);
		}

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
	splitMainPend(currentGroups, expectedSize, relabeledCurrent, mainGroups, pendGroups, nonParticipating);

	/* std::cout << std::endl << std::endl << "Level: " << level << std::endl;
	std::cout << "Current: ";
	printGroupListByOwnSize(relabeledCurrent);
	if (!relabeledCurrent.empty() && !nonParticipating.empty())
		std::cout << " ";
	printGroupListByOwnSize(nonParticipating);
	std::cout << std::endl;
	std::cout << "Main: ";
	printGroupListByOwnSize(mainGroups);
	std::cout << std::endl;
	std::cout << "Pend: ";
	printGroupListByOwnSize(pendGroups);
	std::cout << std::endl;
	std::cout << "Non-participating: ";
	printGroupListByOwnSize(nonParticipating);
	std::cout << std::endl; */
	GroupList mergedMain;
	if (!pendGroups.empty())
	{
		mergedMain = JacobsthalInsertion(mainGroups, pendGroups, level);
	}
	else
	{
		mergedMain = mainGroups;
	}

	// Build the final sequence: merged main followed by non-participating groups.
	GroupList finalSequence = mergedMain;
	for (size_t i = 0; i < nonParticipating.size(); ++i)
		finalSequence.push_back(nonParticipating[i]);

	// Print the flat sequence of integers as required.
	/* std::cout << std::endl << "sequence: ";
	bool first = true;
	for (size_t g = 0; g < finalSequence.size(); ++g)
	{
		for (size_t v = 0; v < finalSequence[g].values.size(); ++v)
		{
			if (!first) std::cout << " ";
			std::cout << finalSequence[g].values[v].value;
			first = false;
		}
	}
	std::cout << std::endl << std::endl; */

	return finalSequence;
}

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



static GroupList recurseGroups(const GroupList& currentGroups, const GroupList& currentTails, int level, size_t totalSize)
{
	// Cuando el tamaño objetivo ya no cabe en el total, o queda un solo grupo, terminamos.
	if (static_cast<size_t>(std::pow(2, level)) > totalSize || currentGroups.size() < 2)
		return currentGroups;

	// En este punto imaginamos un ejemplo como este:
	// level 1: (8) (3) (5) (1) (4)
	// level 2 antes: (8 3) (5 1) (4)
	// level 2 después: (3 8) (1 5) (4)
	// level 3 antes: ((3 8) (1 5)) (4)
	// level 3 después: ((1 5) (3 8)) (4)
	// La función imprime el estado antes y después de ordenar el nivel actual.
	
	//std::cout << "Recursing level " << level << " with " << currentGroups.size() << " groups" << std::endl;
	const size_t expectedSize = static_cast<size_t>(std::pow(2, level - 1));
	//std::cout << "Expected group size: " << expectedSize << std::endl;

	GroupList nextGroups;
	GroupList unpairedGroups;

	// Agrupamos de dos en dos solo si ambos grupos tienen el tamaño esperado.
	// Con el ejemplo anterior: (8) + (3) -> (8 3), luego (5) + (1) -> (5 1).
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
	GroupList visibleTails;
	for (size_t i = 0; i < currentTails.size(); ++i)
	{
		if (currentTails[i].values.size() < expectedSize)
			visibleTails.push_back(currentTails[i]);
	}
	//printRecursionStep("Before", level, currentLevelGroups, visibleTails);

	// Ordenamos cada grupo combinado según la regla de Ford-Johnson.
	// En el ejemplo, [8 3] cambia a [3 8] y [5 1] a [1 5].
	for (size_t i = 0; i < nextGroups.size(); ++i)
		sortGroup(nextGroups[i], level, static_cast<int>(i) + 1);

	currentLevelGroups = nextGroups + unpairedGroups;
	//printRecursionStep("After", level, currentLevelGroups, visibleTails);

	// std::cout << std::endl << std::endl;
	// El siguiente nivel usa los grupos ya combinados más los tails sin tocar.
	// Siguiendo el ejemplo: (8 3) (5 1) -> se vuelven a tratar como piezas del nivel superior.
	GroupList childResult = recurseGroups(currentLevelGroups, visibleTails, level + 1, totalSize);

	//std::cout << "Last step of level " << level << ": ";
	//printGroupList(nextGroups, tails, level);
	//std::cout << std::endl;
	//exit(0);
	//if (level == 3)
	//{
	//	std::cout << "Next groups at level " << level << ": ";
	//	printGroupList(nextGroups, GroupList(), level);
	//	std::cout << std::endl;
	//	std::cout << "Tails at level " << level << ": ";
	//	printGroupList(tails, GroupList(), level);
	//	std::cout << std::endl;
	//	exit(0);
	//}
	// Use the childResult (sequence produced by the deeper level) as the
	// current sequence to work with at this level, then append visible tails.
	GroupList debugCurrent = childResult + visibleTails;
	GroupList merged = insertion(debugCurrent, level);

	// Return the merged sequence so the caller (previous recursion level)
	// receives the concrete sequence to operate on.
	return merged;
}

static GroupList buildInitialGroups(std::deque<int>::iterator begin,
								  std::deque<int>::iterator end)
{
	GroupList groups;

	// Paso inicial del ejemplo: si la entrada es [8 3 5 1], aquí se convierte en
	// [(8), (3), (5), (1)] para poder aplicar el esquema de pares y niveles.
	for (std::deque<int>::iterator it = begin; it != end; ++it)
	{
		GroupNode node;
		node.values.push_back(Element(*it, ""));
		node.key = *it;
		groups.push_back(node);
	}
	return groups;
}

GroupList divideAndSort(std::deque<int>::iterator begin,
							 std::deque<int>::iterator end,
							 int level)
{
	(void)level;
	if (begin == end)
		return GroupList();

	// Convertimos cada número en un grupo de tamaño 1 y arrancamos la recursión.
	// A partir de aquí, el ejemplo va evolucionando nivel a nivel dentro de recurseGroups().
	GroupList currentGroups = buildInitialGroups(begin, end);
	return recurseGroups(currentGroups, GroupList(), 1, static_cast<size_t>(end - begin));
}

void PmergeMe::FordJohnson()
{
	// Punto de entrada del ordenado: toma la deque completa y la pasa al proceso de partición.
	// Ejemplo de flujo: [8 3 5 1 4] -> [(8) (3) (5) (1) (4)] -> [(8 3) (5 1) (4)] -> niveles superiores.
	GroupList finalGroups = ::divideAndSort(_nbrs.begin(), _nbrs.end(), 1);
	_nbrs = flattenGroupList(finalGroups);
}
