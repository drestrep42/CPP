#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;

	_type = "Cat";
	_brain = new Brain();
}
 
Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;

	delete(_brain);
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called" << std::endl;

	this->operator=(copy);
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

std::string	Cat::getType() {
	return (_type);
}

void	Cat::setType(std::string type) {
	this->_type = type;
}
