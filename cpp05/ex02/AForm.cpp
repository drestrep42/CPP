#include "AForm.hpp"

AForm::AForm() : _name("MissingNo"), _signed(false), \
			_grade2sign(75), _grade2execute(75) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool sign, \
			const int grade2sign, const int grade2execute) : _name(name),
			_sign(sign), _grade2sign(grade2sign), _grade2execute(grade2execute) {
	std::cout << "AForm default constructor called" << std::endl;

	if (grade2sign < 1 || grade2execute < 1)
		throw GradeTooHighException();
	if (grade2sign > 150 || grade2execute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {
	std::cout << "AForm default destructor called" << std::endl;
}

AForm::AForm(const AForm& copy) {
	std::cout << "AForm copy constructor called" << std::endl;

	*this = copy;
}

AForm&	AForm::operator=(const AForm& copy) {

	if (this != &copy) {
		this->_grade = copy._grade;
		this->_sign = copy._sign;
		this->_grade2sign = copy._grade2sign;
		this->_grade2execute = copy._grade2execute;
	}
	return (*this);
}

const std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_sign);
}
const int	AForm::getGrade2Sign() const {	
	return (_grade2sign);
}

const int	AForm::getGrade2Execute() const {
	return (_grade2execute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _grade2sign)
		throw GradeTooLowException();
	else
		_sign = true;
}

void	AForm::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	AForm::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	return (os << form.getName() << ", form is signed: " << form.getSigned()
	<< ", grade to sign: " << form.getGrade2Sign() << ", grade to execute: " 
	<< form.getGrade2Execute() << std::endl);
}
