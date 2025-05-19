#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_mantissa = 8;

	public:
		Fixed();
		Fixed(const Fixed& copy);
	
		~Fixed();

		Fixed&	operator=(const Fixed& copy);
	
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
