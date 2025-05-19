#include "Fixed.hpp"

Fixed::Fixed() : _value (0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	//std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
}

Fixed::Fixed(const int nbr) {
	//std::cout << "Int constructor called" << std::endl;
	_value = nbr << _mantissa;
}

Fixed::Fixed(const float nbr) {
	//std::cout << "Float constructor called" << std::endl;
	_value = nbr * (1 << _mantissa);
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}


Fixed& Fixed::operator=(const Fixed& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		_value = copy.getRawBits();
	}
	return (*this);
}

Fixed operator+(const Fixed& first, const Fixed& second) {
	Fixed aux;

	//std::cout << "Plus operator called" << std::endl;
	aux._value = first.getRawBits() + second.getRawBits();
	return (aux);
}

Fixed operator-(const Fixed& first, const Fixed& second) {
	Fixed aux;

	//std::cout << "Minus operator called" << std::endl;
	aux._value = first.getRawBits() - second.getRawBits();
	return (aux);
}

Fixed operator/(const Fixed& first, const Fixed& second) {
	Fixed aux;

	//std::cout << "Division operator called" << std::endl;
	aux._value = (first.getRawBits() << first._mantissa) / second.getRawBits();
	return (aux);
}

Fixed operator*(const Fixed& first, const Fixed& second) {
	Fixed aux;

	//std::cout << "Multiplication operator called" << std::endl;
	aux._value = (first.getRawBits() * second.getRawBits() >> first._mantissa);
	return (aux);
}

bool	operator>(const Fixed& first, const Fixed& second) {
	//std::cout << "Greater-than operator called" << std::endl;
	if (first._value > second._value)
		return (true);
	return (false);
}

bool	operator<(const Fixed& first, const Fixed& second) {
	//std::cout << "Less-than operator called" << std::endl;
	if (first._value < second._value)
		return (true);
	return (false);
}

bool	operator>=(const Fixed& first, const Fixed& second) {
	//std::cout << "Greater-than or equal operator called" << std::endl;
	if (first._value >= second._value)
		return (true);
	return (false);
}

bool	operator<=(const Fixed& first, const Fixed& second) {
	//std::cout << "Less-than or equal operator called" << std::endl;
	if (first._value <= second._value)
		return (true);
	return (false);
}

bool	operator==(const Fixed& first, const Fixed& second) {
	//std::cout << "Equality operator called" << std::endl;
	if (first._value == second._value)
		return (true);
	return (false);
}

bool	operator!=(const Fixed& first, const Fixed& second) {
	//std::cout << "Not equal operator called" << std::endl;
	if (first._value != second._value)
		return (true);
	return (false);
}

Fixed& Fixed::operator++() {
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed&	Fixed::operator--() {
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	this->_value--;
	return (tmp);
}

int		Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _mantissa));
}

int	Fixed::toInt( void ) const {
	return (_value >> _mantissa);
}

Fixed&	Fixed::min(Fixed& first, Fixed& second) {
	if (first < second)
		return (first);
	return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
	if (first < second)
			return (first);
		return (second);
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
	if (first > second)
		return (first);
	return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
	if (first > second)
			return (first);
		return (second);
}
