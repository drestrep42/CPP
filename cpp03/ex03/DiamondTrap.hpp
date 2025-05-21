#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap: virtual public ClapTrap, virtual public FragTrap, virtual ScavTrap {

	private:
		std::string	_name;

	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
		void	guardGate();
};

#endif
