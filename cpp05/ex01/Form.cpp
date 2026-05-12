#include "Form.hpp"

Form::Form() : _name("MissingNo"), _is_signed(false), \
			_grade2sign(75), _grade2execute(75) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, bool is_signed, \
			const int grade2sign, const int grade2execute) : _name(name),
			_is_signed(is_signed), _grade2sign(grade2sign), _grade2execute(grade2execute) {
	std::cout << "Form default constructor called" << std::endl;

	if (grade2sign < 1 || grade2execute < 1)
		throw GradeTooHighException();
	if (grade2sign > 150 || grade2execute > 150)
		throw GradeTooLowException();
	if (is_signed)
		throw FormShouldBeUnsignedException();
}

Form::~Form() {
	std::cout << "Form default destructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _is_signed(copy._is_signed), \
			_grade2sign(copy._grade2sign), _grade2execute(copy._grade2execute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& copy) {
	_is_signed = copy._is_signed;
	return (*this);
}

const std::string	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_is_signed);
}

int	Form::getGrade2Sign() const {	
	return (_grade2sign);
}

int	Form::getGrade2Execute() const {
	return (_grade2execute);
}

bool	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade2sign)
		throw BureaucratTooLowException();
	else
		_is_signed = true;
	return (_is_signed);
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	return (os << form.getName() << ", form is signed: " << form.getSigned()
	<< ", grade to sign: " << form.getGrade2Sign() << ", grade to execute: " 
	<< form.getGrade2Execute() << std::endl);
}
