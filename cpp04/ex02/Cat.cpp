#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;

	_type = "Cat";
	_brain = new Brain();
	std::cout << std::endl;
}
 
Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;

	delete(_brain);
}

Cat::Cat(const Cat& copy) {
	std::cout << "Cat copy constructor called" << std::endl;

	*this = copy;
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
		this->_brain = new Brain (*copy._brain);
	}
	return (*this);
}

std::string	Cat::getType() {
	return (_type);
}

void	Cat::setType(std::string type) {
	_type = type;
}

std::string	Cat::getIdea(int nbr) const {
	if (nbr < 0 || nbr > 99)
		return ("Idea number has to be between 0 and 99");
	return (_brain->getIdea(nbr));
}

void		Cat::setIdea(std::string idea, int nbr) {
	if (nbr < 0) {
		std::cout << "Idea number has to be positive" << std::endl;
		return ;
	}
	if (nbr >= 100)
		nbr = nbr - 100;
	_brain->setIdea(idea, nbr);
}

void	Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}
