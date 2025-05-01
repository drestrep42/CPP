#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;
	
	public:
		Weapon() {}
		~Weapon() {}
		const	std::string	*getType( void ) { return (&type); }
		void	setType(std::string value) { type = value; }
};

#endif
