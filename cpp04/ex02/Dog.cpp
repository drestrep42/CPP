#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;

	_type = "Dog";
	_brain = new Brain();
	std::cout << std::endl;
}
 
Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;

	delete(_brain);
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called" << std::endl;

	this->operator=(copy);
}

Dog&	Dog::operator=(const Dog& copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
		this->_brain = copy._brain;
	}
	return (*this);
}

std::string	Dog::getType() {
	return (_type);
}

void	Dog::setType(std::string type) {
	_type = type;
}

std::string	Dog::getIdea(int nbr) const {
	return (_brain->getIdea(nbr));
}

void	Dog::setIdea(std::string idea, int nbr) {
	_brain->setIdea(idea, nbr);
}

void	Dog::makeSound() const {
	std::cout << "Dog" << std::endl;
}