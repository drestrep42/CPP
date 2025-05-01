#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanA(Weapon w) { weapon = w; }
		~HumanA() {}
		void	attack(void) {
			std::cout << name << "attacks with their" << weapon.getType();
		};
};

#endif
