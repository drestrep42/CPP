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

	std::stack<int> s(mstack);
	while (s.size() > 0)
	{
		std::cout << "Stack element: " << s.top() << std::endl;
		s.pop();
	}
	std::cout << "\n --------------------- \n\n";

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top element: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it_lst = lst.begin();
	std::list<int>::iterator ite_lst = lst.end();
	++it_lst;
	--it_lst;
	while (it_lst != ite_lst){
		std::cout << "Element: " << *it_lst << std::endl;
		++it_lst;
	}

	return 0;
}
