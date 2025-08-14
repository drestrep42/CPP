#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat default constructor called" << std::endl;

	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Error creating " << _name << ": " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Error creating " << _name << ": " << e.what() << '\n';
	}
	_grade = grade;
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
	try
	{
		if (!_grade) {
			std::cout << _name << " doesn't have a grade!" << std::endl;
			return ;
		}
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what();
	}
}

void	Bureaucrat::decrementGrade() {
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what();
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	if (!bureaucrat.getGrade())
		return (os << bureaucrat.getName() << " doesn't have a grade!" << std::endl);
	return (os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl);
}
