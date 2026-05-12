#include "Intern.hpp"

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

}
