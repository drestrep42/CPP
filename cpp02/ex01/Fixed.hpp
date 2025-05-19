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

		Fixed&		operator=(const Fixed& copy);
	
		friend		std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

		float		toFloat( void ) const;
		int			toInt( void ) const;
};


#endif
