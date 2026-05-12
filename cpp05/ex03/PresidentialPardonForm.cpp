#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", false, 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", false, 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

void PresidentialPardonForm::pardon() const {
	std::cout << this->_target << " has been pardoned by the Zaphod Beeblebrox!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGrade2Execute()) {
		throw AForm::BureaucratTooLowToExecuteException();
	}
	this->pardon();
}
