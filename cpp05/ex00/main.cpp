#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	mango("mango", 2);
	Bureaucrat	kiwi("kiwi", 0);

	std::cout << std::endl;
	std::cout << mango;
	mango.incrementGrade();

	std::cout << std::endl;
	std::cout << mango;
	mango.incrementGrade();

	std::cout << std::endl;
	std::cout << mango;
	mango.decrementGrade();
	std::cout << mango;

	std::cout << std::endl;
	std::cout << kiwi;
	kiwi.incrementGrade();
	std::cout << kiwi;
}
