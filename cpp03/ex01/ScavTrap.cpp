#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << _name << " constructor called." << std::endl;

	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor called." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void	ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << _name << " lost " << amount << " HP!" << std::endl;	

}

void	ScavTrap::beRepaired(unsigned int amount) {
	std::cout << "ScavTrap " << _name << " healed " << amount << " HP!" << std::endl;	
}


void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
