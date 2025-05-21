#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string s) : _name(s) {
	std::cout << "ClapTrap " << _name << " constructor called." << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " lost " << amount << " HP!" << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " healed " << amount << " HP!" << std::endl;	
}
