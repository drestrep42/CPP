#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
 
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;

	this->operator=(copy);
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType() const {
	return (_type);
}

void	WrongAnimal::setType(std::string type) {
	this->_type = type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "*This animal makes all sounds*" << std::endl;
}
