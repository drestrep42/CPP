#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_mantissa = 8;

	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int nbr);
		Fixed(const float nbr);

		~Fixed();

		Fixed&					operator=(const Fixed& copy);

		friend std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

		friend bool				operator>(const Fixed& first, const Fixed& second);
		friend bool				operator<(const Fixed& first, const Fixed& second);
		friend bool				operator>=(const Fixed& first, const Fixed& second);
		friend bool				operator<=(const Fixed& first, const Fixed& second);
		friend bool				operator==(const Fixed& first, const Fixed& second);
		friend bool				operator!=(const Fixed& first, const Fixed& second);

		friend Fixed			operator+(const Fixed& first, const Fixed& second);
		friend Fixed			operator-(const Fixed& first, const Fixed& second);
		friend Fixed			operator*(const Fixed& first, const Fixed& second);
		friend Fixed			operator/(const Fixed& first, const Fixed& second);

		Fixed&					operator++();
		Fixed					operator++(int);
		Fixed&					operator--();
		Fixed					operator--(int);

		int						getRawBits( void ) const;
		void					setRawBits( int const raw );

		float					toFloat( void ) const;
		int						toInt( void ) const;

		static Fixed&			min(Fixed& first, Fixed& second);
		static Fixed&			max(Fixed& first, Fixed& second);
		static const Fixed&		min(const Fixed& first, const Fixed& second);
		static const Fixed&		max(const Fixed& first, const Fixed& second);
		
};

#endif
