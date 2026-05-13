#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm* form;
	{
		Intern someRandomIntern;
		form = someRandomIntern.makeForm("robotomy request", "Pepe");
		delete form;
	}
	
	std::cout << "\n --------------------- \n\n";
	
	{
		Intern someRandomIntern;
		form = someRandomIntern.makeForm("shrubbery creation form", "Marvin");
		delete form;
	}

	std::cout << "\n --------------------- \n\n";
	
	{
		Intern someRandomIntern;
		form = someRandomIntern.makeForm("presidential pardon form", "Gerundio");
		delete form;
	}
	
	std::cout << "\n --------------------- \n\n";
	return (0);
}
