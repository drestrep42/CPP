#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/* int main() {
    Fixed a;
    Fixed b(5.05f);
    Fixed c(2);
    Fixed const d(Fixed(9.1f));
    Fixed const e(Fixed(10.1001f));
    
    std::cout << "\nInitial values:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    std::cout << "\nArithmetic operators:" << std::endl;
    std::cout << "b + c = " << b + c << std::endl;
    std::cout << "b - c = " << b - c << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    std::cout << "b / c = " << b / c << std::endl;

    std::cout << "\nComparison operators:" << std::endl;
    std::cout << "d > e: " << (d > e) << std::endl;
    std::cout << "d < e: " << (d < e) << std::endl;
    std::cout << "d >= e: " << (d >= e) << std::endl;
    std::cout << "d <= e: " << (d <= e) << std::endl;
    std::cout << "d == e: " << (d == e) << std::endl;
    std::cout << "d != e: " << (d != e) << std::endl;

    std::cout << "\nIncrement / Decrement operators:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "\nMin / Max functions:" << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;

    return 0;
} */
