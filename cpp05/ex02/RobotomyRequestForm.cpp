#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", false, 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", false, 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

void RobotomyRequestForm::robotomize() const {
	int random = std::rand() % 2;

	try {
		if (random == 0) {
			std::cout << "** DRILLING NOISES **" << std::endl;
			std::cout << this->_target << " has been robotomized!" << std::endl;
		} else {
			std::cout << "The robotomy has failed on " << this->_target << "!" << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGrade2Execute()) {
		throw AForm::GradeTooLowException();
	}
	this->robotomize();
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form) {
	str << "Form Name: " << form.getName() << std::endl;
	str << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
	str << "Grade required to sign: " << form.getGrade2Sign() << std::endl;
	str << "Grade required to execute: " << form.getGrade2Execute() << std::endl;
	str << "Target: " << form._target << std::endl;
	return (str);
}
