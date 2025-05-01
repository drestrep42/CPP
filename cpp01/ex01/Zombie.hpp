#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	
	public:
		Zombie() {};
		~Zombie() {};
		void	setName( std::string n) { name = n; }
		void	announce( void );
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

Zombie* zombieHorde( int N, std::string name );

#endif
