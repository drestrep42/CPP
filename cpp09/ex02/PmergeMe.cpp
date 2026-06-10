#include "PmergeMe.hpp"

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

static void sortGroup(GroupNode& group, int level)
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
	std::deque<int> left(group.values.begin(), group.values.begin() + childSize);
	std::deque<int> right(group.values.begin() + childSize, group.values.begin() + childSize * 2);

	// Si el último elemento de la mitad izquierda es mayor que el último de la derecha, se intercambian las mitades.
	if (!left.empty() && !right.empty() && left.back() > right.back())
	{
		std::deque<int> swapped;
		swapped.insert(swapped.end(), right.begin(), right.end());
		swapped.insert(swapped.end(), left.begin(), left.end());
		group.values = swapped;
	}
	// Después de ordenar el grupo, se actualiza su clave al último elemento del grupo, que es el mayor.
	//En el ejemplo, después de ordenar [3 8 1 5] a [1 5 3 8], la clave se actualiza a 8.
	group.key = group.values.back();
}

static void printValues(const std::deque<int>& values)
{
	// Imprime una secuencia plana separando sus elementos por espacios.
	for (size_t i = 0; i < values.size(); ++i)
	{
		std::cout << values[i];
		if (i + 1 != values.size())
			std::cout << " ";
	}
}

static void printGroup(const std::deque<int>& values, int level, bool levelOneNestedSingles)
{
	// Reconstuye visualmente un grupo con paréntesis anidados para que se vea
	// cómo los números se van agrupando por niveles en el algoritmo.
	std::cout << "(";
	if (level <= 1)
	{
		if (levelOneNestedSingles && values.size() == 2)
			std::cout << "(" << values[0] << ") (" << values[1] << ")";
		else
			printValues(values);
	}
	else
	{
		const size_t childSize = static_cast<size_t>(std::pow(2, level - 1));
		for (size_t i = 0; i < values.size(); i += childSize)
		{
			std::deque<int> child(values.begin() + i, values.begin() + i + childSize);
			printGroup(child, level - 1, false);
			if (i + childSize < values.size())
				std::cout << " ";
		}
	}
	std::cout << ")";
}

static int levelFromSize(size_t size)
{
	// Calcula el nivel mínimo necesario para representar una secuencia de ese tamaño.
	int level = 1;
	while ((static_cast<size_t>(std::pow(2, level))) < size)
		++level;
	return level;
}

static void printGroupList(const GroupList& groups,
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
}

static void printRecursionStep(const char* label, int level,
							   const GroupList& groups, const GroupList& tails)
{
	// Label es "Before" o "After" para indicar el estado del nivel actual antes y después de ordenar los grupos.
	// Etiqueta un estado intermedio de la recursión para poder comparar el antes y el después.
	std::cout << label << " level " << level << ": ";
	printGroupList(groups, tails, level);
	std::cout << std::endl;
}

static GroupNode combineGroups(const GroupNode& left, const GroupNode& right)
{
	// Une dos grupos contiguos preservando el orden original de sus elementos.
	GroupNode parent;
	parent.values = left.values;
	parent.values.insert(parent.values.end(), right.values.begin(), right.values.end());
	parent.key = parent.values.back();
	return parent;
}

static void recurseGroups(const GroupList& currentGroups, int level, size_t totalSize)
{
	// Cuando el tamaño objetivo ya no cabe en el total, o queda un solo grupo, terminamos.
	if (static_cast<size_t>(std::pow(2, level)) > totalSize || currentGroups.size() < 2)
		return;

	// En este punto imaginamos un ejemplo como este:
	// level 1: (8) (3) (5) (1) (4)
	// level 2 antes: (8 3) (5 1) (4)
	// level 2 después: (3 8) (1 5) (4)
	// level 3 antes: ((3 8) (1 5)) (4)
	// level 3 después: ((1 5) (3 8)) (4)
	// La función imprime el estado antes y después de ordenar el nivel actual.
	std::cout << "Recursing level " << level << " with " << currentGroups.size() << " groups" << std::endl;
	const size_t expectedSize = static_cast<size_t>(std::pow(2, level - 1));
	std::cout << "Expected group size: " << expectedSize << std::endl;

	GroupList nextGroups;
	GroupList tails;

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

	// Si sobra un grupo que no puede emparejarse, se guarda como "tail" y se arrastra al siguiente nivel.
	for (; i < currentGroups.size(); ++i)
		tails.push_back(currentGroups[i]);

	printRecursionStep("Before", level, nextGroups, tails);

	// Ordenamos cada grupo combinado según la regla de Ford-Johnson.
	// En el ejemplo, [8 3] cambia a [3 8] y [5 1] a [1 5].
	for (size_t i = 0; i < nextGroups.size(); ++i)
		sortGroup(nextGroups[i], level);

	printRecursionStep("After", level, nextGroups, tails);

	std::cout << std::endl << std::endl;
	// El siguiente nivel usa los grupos ya combinados más los tails sin tocar.
	// Siguiendo el ejemplo: (8 3) (5 1) -> se vuelven a tratar como piezas del nivel superior.
	GroupList nextCurrent = nextGroups;
	for (size_t i = 0; i < tails.size(); ++i)
		nextCurrent.push_back(tails[i]);
	recurseGroups(nextCurrent, level + 1, totalSize);

	
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
		node.values.push_back(*it);
		node.key = *it;
		groups.push_back(node);
	}
	return groups;
}

void PmergeMe::divideAndSort(std::deque<int>::iterator begin,
							 std::deque<int>::iterator end,
							 int level)
{
	(void)level;
	if (begin == end)
		return;

	// Convertimos cada número en un grupo de tamaño 1 y arrancamos la recursión.
	// A partir de aquí, el ejemplo va evolucionando nivel a nivel dentro de recurseGroups().
	GroupList currentGroups = buildInitialGroups(begin, end);
	recurseGroups(currentGroups, 1, static_cast<size_t>(end - begin));
}

void PmergeMe::FordJohnson()
{
	// Punto de entrada del ordenado: toma la deque completa y la pasa al proceso de partición.
	// Ejemplo de flujo: [8 3 5 1 4] -> [(8) (3) (5) (1) (4)] -> [(8 3) (5 1) (4)] -> niveles superiores.
	divideAndSort(_nbrs.begin(), _nbrs.end(), 1);
}
