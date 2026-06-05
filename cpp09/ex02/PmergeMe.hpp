#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>

class PmergeMe
{
    private:
        std::deque<int> nbrs;

    public:
        PmergeMe(/* args */);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
};

#endif
