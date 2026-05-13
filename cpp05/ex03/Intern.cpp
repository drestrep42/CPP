#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {"shrubbery creation form", "robotomy request form", "presidential pardon form"};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}
