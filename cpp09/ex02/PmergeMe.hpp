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

GroupList operator+(const GroupList& first, const GroupList& second);

void FordJohnson(std::deque<int>& nbrs);
void printDeque(const std::deque<int>& nbrs, bool sorted);

#endif
