#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanB() {}
		~HumanB() {}
		void	attack(void) {
			std::cout << name << "attacks with their" << weapon.getType();
		};
};

#endif
