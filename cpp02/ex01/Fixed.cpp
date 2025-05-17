#include "Fixed.hpp"

Fixed::Fixed() : _value (0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		_value = copy.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	_value = nbr << _mantissa;
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	_value = nbr * (1 << _mantissa);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _mantissa));
}

int	Fixed::toInt( void ) const {
	return (_value >> _mantissa);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}
