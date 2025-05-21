#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << _name << " constructor called." << std::endl;
	
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void	FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FragTrap " << _name << " lost " << amount << " HP!" << std::endl;	

}

void	FragTrap::beRepaired(unsigned int amount) {
	std::cout << "FragTrap " << _name << " healed " << amount << " HP!" << std::endl;	
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requestsa High-Five!!!" << std::endl;
}
