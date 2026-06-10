#include "PmergeMe.hpp"

static void printValues(const IntDeque& values)
{
	for (size_t i = 0; i < values.size(); ++i)
	{
		std::cout << values[i];
		if (i + 1 != values.size())
			std::cout << " ";
	}
}

static void printGroup(const IntDeque& values, int level, bool levelOneNestedSingles)
{
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
		const size_t childSize = static_cast<size_t>(1U << (level - 1));
		for (size_t i = 0; i < values.size(); i += childSize)
		{
			IntDeque child(values.begin() + i, values.begin() + i + childSize);
			printGroup(child, level - 1, false);
			if (i + childSize < values.size())
				std::cout << " ";
		}
	}
	std::cout << ")";
}

static int levelFromSize(size_t size)
{
	int level = 1;
	while ((static_cast<size_t>(1U) << level) < size)
		++level;
	return level;
}

static void printGroupList(const GroupList& groups,
					   const GroupList& tails,
					   int level)
{
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

static GroupNode combineGroups(const GroupNode& left, const GroupNode& right)
{
	GroupNode parent;
	parent.values = left.values;
	parent.values.insert(parent.values.end(), right.values.begin(), right.values.end());
	parent.key = parent.values.back();
	return parent;
}

static void sortGroup(GroupNode& group, int level)
{
	if (group.values.size() < 2)
		return;

	const size_t childSize = static_cast<size_t>(1U << (level - 1));
	if (group.values.size() < childSize * 2)
		return;

	IntDeque left(group.values.begin(), group.values.begin() + childSize);
	IntDeque right(group.values.begin() + childSize, group.values.begin() + childSize * 2);
	if (!left.empty() && !right.empty() && left.back() > right.back())
	{
		IntDeque swapped;
		swapped.insert(swapped.end(), right.begin(), right.end());
		swapped.insert(swapped.end(), left.begin(), left.end());
		group.values = swapped;
	}
	group.key = group.values.back();
}

static void printRecursionStep(const char* label,
							   int level,
							   const GroupList& groups,
							   const GroupList& tails)
{
	std::cout << label << " level " << level << ": ";
	printGroupList(groups, tails, level);
	std::cout << std::endl;
}

static GroupList buildInitialGroups(std::deque<int>::iterator begin,
								  std::deque<int>::iterator end)
{
	GroupList groups;

	for (std::deque<int>::iterator it = begin; it != end; ++it)
	{
		GroupNode node;
		node.values.push_back(*it);
		node.key = *it;
		groups.push_back(node);
	}
	return groups;
}

static void recurseGroups(const GroupList& currentGroups, int level, size_t totalSize)
{
	if (static_cast<size_t>(1U << level) > totalSize || currentGroups.size() < 2)
		return;

	const size_t expectedSize = static_cast<size_t>(1U << (level - 1));

	GroupList nextGroups;
	GroupList tails;

	size_t i = 0;
	while (i + 1 < currentGroups.size())
	{
		if (currentGroups[i].values.size() != expectedSize
			|| currentGroups[i + 1].values.size() != expectedSize)
			break;

		nextGroups.push_back(combineGroups(currentGroups[i], currentGroups[i + 1]));
		i += 2;
	}

	for (; i < currentGroups.size(); ++i)
		tails.push_back(currentGroups[i]);

	printRecursionStep("Before", level, nextGroups, tails);

	for (size_t i = 0; i < nextGroups.size(); ++i)
		sortGroup(nextGroups[i], level);

	printRecursionStep("After", level, nextGroups, tails);

	GroupList nextCurrent = nextGroups;
	for (size_t i = 0; i < tails.size(); ++i)
		nextCurrent.push_back(tails[i]);
	recurseGroups(nextCurrent, level + 1, totalSize);
}

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

void PmergeMe::FordJohnson()
{
	divideAndSort(_nbrs.begin(), _nbrs.end(), 1);
}

void PmergeMe::divideAndSort(std::deque<int>::iterator begin,
							 std::deque<int>::iterator end,
							 int level)
{
	(void)level;
	if (begin == end)
		return;

	GroupList currentGroups = buildInitialGroups(begin, end);
	recurseGroups(currentGroups, 1, static_cast<size_t>(end - begin));
}

void PmergeMe::sort(int recursion_lvl)
{
	//blablabla
	(void)recursion_lvl;
}

void PmergeMe::print(bool sorted) const
{
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
