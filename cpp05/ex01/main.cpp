#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Elena("Elena", 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	try
	{
		Bureaucrat Andrei("Andrei", 151);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;

	Bureaucrat Mixi;
	Bureaucrat Viseras ("Viseras", 1);

	std::cout << Mixi;
	std::cout << Viseras;
	try
	{
		Mixi.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;
	std::cout << Mixi;
	std::cout << Viseras;

	Bureaucrat b=Viseras;

	std::cout << b;
}
