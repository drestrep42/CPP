#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat Elena("Elena", 0);
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat Andrei("Andrei", 151);
	} catch(std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	Bureaucrat Mixi;
	Bureaucrat Viseras ("Viseras", 1);

	std::cout << Mixi;
	std::cout << Viseras << std::endl;

	try {
		Mixi.decrementGrade();
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << Mixi;
	std::cout << Viseras;

	Bureaucrat a=Viseras;
	Bureaucrat b("Temp", 75);

	std::cout << std::endl << a;
	std::cout << b << std::endl;

	b = a;
	std::cout << b << std::endl;

}
