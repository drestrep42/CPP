#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

class MutantStack : public std::stack<int>
{
	public:
		MutantStack();

		template <typename T>
		MutantStack(T value);
		template <typename T>
		MutantStack(const MutantStack<T>& other) : std::stack<int>(other) {};

		~MutantStack();

		typedef std::stack<int>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

MutantStack::MutantStack() {}

MutantStack::~MutantStack(){}

MutantStack::iterator MutantStack::begin()
{
	return this->c.begin();
}

MutantStack::iterator MutantStack::end()
{
	return this->c.end();
}

#endif