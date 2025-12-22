#include "Form.hpp"

Form::Form() : _name("MissingNo"), _signed(false), \
			_grade2sign(75), _grade2execute(75) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, bool sign, \
			const int grade2sign, const int grade2execute) : _name(name),
			_sign(sign), _grade2sign(grade2sign), _grade2execute(grade2execute) {
	std::cout << "Form default constructor called" << std::endl;

	if (grade2sign < 1 || grade2execute < 1)
		throw GradeTooHighException();
	if (grade2sign > 150 || grade2execute >ñ 150)
		throw GradeTooLowException();
}

Form::~Form() {
	std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form& copy) {
	std::cout << "Form copy constructor called" << std::endl;

	*this = copy;
}

Form&	Form::operator=(const Form& copy) {

	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

const std::string	Form::getName() const {
	return (_name);
}

int					Form::getGrade() const {
	return (_grade);
}

void	Form::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Form::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	return (os << form.getName() << ", form grade " << form.getGrade() << std::endl);
}
