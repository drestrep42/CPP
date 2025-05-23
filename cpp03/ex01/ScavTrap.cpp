#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

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

ScavTrap::ScavTrap(const ScavTrap& copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;

	this->operator=(copy);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_name = copy.getName();
		this->_name = copy.getName();
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " can't attack, is dead!" << std::endl;	
}

void	ScavTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoints > 0) {
		std::cout << "ScavTrap " << _name << " lost " << amount << " HP!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		if (_hitPoints == 0)
			std::cout << "ScavTrap " << _name << " died!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " is already dead!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {

	if (_hitPoints == 0) {
		std::cout << "ScavTrap "  << _name << " is dead, he can't be revived!"<< std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy left!" << std::endl;
		_hitPoints += amount;
	}
	else if (amount <= 0) {
		std::cout << "Amount has to be positive 😒" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << _name << " healed " << amount << " HP!" << std::endl;	
		_hitPoints += amount;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
