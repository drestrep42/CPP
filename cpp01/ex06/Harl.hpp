#ifndef HARL_HPP
#define  HARL_HPP

#include <map>
#include <iostream>
#include <unistd.h>

#define USAGE_ERROR "Correct use: ./harlFilter DEBUG/INFO/WARNING/ERROR"

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl();
		~Harl();
		void	complain( std::string level);
	};
#endif
