#include "AForm.hpp"

AForm::AForm() : _name("MissingNo"), _is_signed(false), \
			_grade2sign(75), _grade2execute(75) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool is_signed, \
			const int grade2sign, const int grade2execute) : _name(name),
			_is_signed(is_signed), _grade2sign(grade2sign), _grade2execute(grade2execute) {
	std::cout << "AForm default constructor called" << std::endl;

	if (grade2sign < 1 || grade2execute < 1)
		throw GradeTooHighException();
	if (grade2sign > 150 || grade2execute > 150)
		throw GradeTooLowException();
	if (_is_signed)
		throw FormShouldBeUnsignedException();
}

AForm::~AForm() {
	std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _is_signed(copy._is_signed), \
			_grade2sign(copy._grade2sign), _grade2execute(copy._grade2execute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& copy) {
	_is_signed = copy._is_signed;
	return (*this);
}

const std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_is_signed);
}

int	AForm::getGrade2Sign() const {	
	return (_grade2sign);
}

int	AForm::getGrade2Execute() const {
	return (_grade2execute);
}

bool	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade2sign)
		throw BureaucratTooLowException();
	else
		_is_signed = true;
	return (_is_signed);
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	return (os << form.getName() << ", form is signed: " << form.getSigned()
	<< ", grade to sign: " << form.getGrade2Sign() << ", grade to execute: " 
	<< form.getGrade2Execute() << std::endl);
}
