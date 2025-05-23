#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {

	std::cout << "DiamondTrap " << _name << " constructor called." << std::endl;

	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;

	this->operator=(copy);
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_name = copy.getName();
		this->_name = copy.getName();
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "DiamondTrap " << _name << " has no energy left, he can't attack!" << std::endl;
	}
	else
		std::cout << "DiamondTrap " << _name << " can't attack, is dead!" << std::endl;	
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoints > 0) {
		std::cout << "DiamondTrap " << _name << " lost " << amount << " HP!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		if (_hitPoints == 0)
			std::cout << "DiamondTrap " << _name << " died!" << std::endl;
	}
	else
		std::cout << "DiamondTrap " << _name << " is already dead!" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount) {

	if (_hitPoints == 0) {
		std::cout << "DiamondTrap "  << _name << " is dead, he can't be revived!"<< std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "DiamondTrap " << _name << " has no energy left, he can't be repaired!" << std::endl;
		_hitPoints += amount;
	}
	else if (amount <= 0) {
		std::cout << "Amount has to be positive 😒" << std::endl;
	}
	else {
		std::cout << "DiamondTrap " << _name << " healed " << amount << " HP!" << std::endl;	
		_hitPoints += amount;
		_energyPoints--;
	}
}

void	DiamondTrap::whoAmI() {
	std::cout << "Diamond Trap's name: " << _name << std::endl;
	std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
}
