#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = "Great Idea number " + std::to_string(i);
	std::cout << "Brain default constructor called" << std::endl;
}
 
Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;

	this->operator=(copy);
}

Brain&	Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called" << std::endl;

	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdeas(int nbr) const {
	return (_ideas[nbr]);
}

void	Brain::setIdeas(std::string idea, int nbr) {
	this->_ideas[nbr] = idea;
}
