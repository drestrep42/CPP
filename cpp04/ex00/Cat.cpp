#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}
 
Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called" << std::endl;

	*this = copy;
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

void	Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
