#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", false, 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	
	if (this != &copy) {
		this->_target = copy._target;
	}
	return (*this);
}

void ShrubberyCreationForm::writeTrees(const std::string& filename) const {
	std::ofstream file(filename.c_str());
	
	if (!file.is_open()) {
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	file << "      _____" << std::endl;
	file << "    /******\\" << std::endl;
	file << " /************\\" << std::endl;
	file << "{**************}" << std::endl;
	file << " \\************/" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   ||| _- _" << std::endl;
	file << "  _ -  |||   -_" << std::endl;
	file << "      // \\\\" << std::endl;

	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getGrade2Execute()) {
		throw AForm::GradeTooLowException();
	}
	this->writeTrees(this->_target + "_shrubbery");
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form) {
	str << "Form Name: " << form.getName() << std::endl;
	str << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl;
	str << "Grade required to sign: " << form.getGrade2Sign() << std::endl;
	str << "Grade required to execute: " << form.getGrade2Execute() << std::endl;
	str << "Target: " << form._target << std::endl;
	return (str);
}
