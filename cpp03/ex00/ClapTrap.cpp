#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string s) : _name(s) {
	std::cout << "Constructor called" << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " took " << amount << " HP " << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " repaired " << amount << " of HP " << std::endl;	
}
