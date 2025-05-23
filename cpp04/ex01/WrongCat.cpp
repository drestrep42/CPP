#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}
 
WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;

	this->operator=(copy);
}

WrongCat&	WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

std::string	WrongCat::getType() {
	return (_type);
}

void	WrongCat::setType(std::string type) {
	this->_type = type;
}
