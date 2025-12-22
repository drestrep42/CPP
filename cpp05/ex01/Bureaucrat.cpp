#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("MissingNo"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat default constructor called" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;

	*this = copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy) {

	if (this != &copy) {
		this->_grade = copy._grade;
	}
	return (*this);
}

const std::string	Bureaucrat::getName() const {
	return (_name);
}

int					Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl);
}
