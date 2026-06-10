#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>

struct Element
{
    int value;
    std::string label;

    Element() : value(0), label() {}
    Element(int v, const std::string& l) : value(v), label(l) {}
};

struct GroupNode
{
    std::deque<Element> values;
    int key;

    GroupNode() : values(), key(0) {}
};

typedef std::deque<GroupNode> GroupList;

class PmergeMe
{
    private:
        std::deque<int> _nbrs;

    public:
        PmergeMe();
		PmergeMe(char **begin, char **end);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

		void FordJohnson();

		void divideAndSort(std::deque<int>::iterator begin,
                   std::deque<int>::iterator end, int level);

		void print(bool sorted) const;
};

#endif
