#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

struct GroupNode
{
    std::deque<int> values;
    int key;
};

typedef std::vector<GroupNode> GroupList;

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
