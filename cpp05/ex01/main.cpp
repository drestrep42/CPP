#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form form1("Form", false, 0, 1);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Form form1("Form", true, 10, 1);
	} catch(std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	Form form1("Form", false, 10, 1);
	Bureaucrat corrector ("Corrector", 11);

	std::cout << form1;
	std::cout << corrector << std::endl;

	try {
		corrector.signForm(form1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	corrector.incrementGrade();

	try {
		corrector.signForm(form1);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	

	std::cout << std::endl;
	std::cout << corrector;
	std::cout << form1 << std::endl;
}
