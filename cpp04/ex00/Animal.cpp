#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}
 
Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called" << std::endl;

	this->operator=(copy);
}

Animal&	Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

std::string	Animal::getType() const {
	return (_type);
}

void	Animal::setType(std::string type) {
	this->_type = type;
}

void	Animal::makeSound() const {
	std::cout << "*This animal doesn't make any sound*" << std::endl;
}