#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();

	std::cout << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << "Element: " << *it << std::endl;
		++it;
	}

	std::cout << "\n --------------------- \n\n";

	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	while (cit != cite)
	{
		std::cout << "Element: " << *cit << std::endl;
		++cit;
	}

	std::cout << "\n --------------------- \n\n";

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << "Element: " << *rit << std::endl;
		++rit;
	}

	std::cout << "\n --------------------- \n\n";

	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	while (crit != crite)
	{
		std::cout << "Element: " << *crit << std::endl;
		++crit;
	}
	return 0;
}
