#include "FragTrap.hpp"

FragTrap::FragTrap() {}

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

FragTrap::FragTrap(const FragTrap& copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;

	this->operator=(copy);
}

FragTrap&	FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_name = copy.getName();
		this->_name = copy.getName();
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " has no energy left, he can't attack!" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " can't attack, is dead!" << std::endl;	
}

void	FragTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoints > 0) {
		std::cout << "FragTrap " << _name << " lost " << amount << " HP!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		if (_hitPoints == 0)
			std::cout << "FragTrap " << _name << " died!" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " is already dead!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount) {

	if (_hitPoints == 0) {
		std::cout << "FragTrap "  << _name << " is dead, he can't be revived!"<< std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " has no energy left, he can't be repaired!" << std::endl;
		_hitPoints += amount;
	}
	else if (amount <= 0) {
		std::cout << "Amount has to be positive 😒" << std::endl;
	}
	else {
		std::cout << "FragTrap " << _name << " healed " << amount << " HP!" << std::endl;	
		_hitPoints += amount;
		_energyPoints--;
	}
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " requests a High-Five!!!" << std::endl;
}
