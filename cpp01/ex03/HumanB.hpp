#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon		*weapon;
		std::string	name;

	public:
		HumanB(std::string s);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &w);
};

#endif
