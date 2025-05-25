#include "Brain.hpp"

Brain::Brain() {

	for (int i = 0; i < 100; i++) {
		std::stringstream	ss;
		ss << "Great Idea number " << i;
		this->_idea[i] = ss.str();
	}
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
			this->_idea[i] = copy._idea[i];
	}
	return (*this);
}

std::string	Brain::getIdea(int nbr) const {
	return (_idea[nbr]);
}

void	Brain::setIdea(std::string idea, int nbr) {
	_idea[nbr] = idea;
}
