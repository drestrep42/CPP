#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string s) : _name(s) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;

	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "ClapTrap copy constructor called" << std::endl;

	this->operator=(copy);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &copy) {
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_name = copy.getName();
		this->_name = copy.getName();
	}
	return (*this);
}

std::string	ClapTrap::getName() const {
	return (_name);
}

int	ClapTrap::getHitPoints() const {
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints() const {
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage() const {
	return (_attackDamage);
}

void	ClapTrap::attack(const std::string& target) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left, he can't attack!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attack, is dead!" << std::endl;	
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	if (_hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " lost " << amount << " HP!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " died!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (_hitPoints <= 0) {
		std::cout << "ClapTrap "  << _name << " is dead, he can't be revived!"<< std::endl;
	}
	else if (_hitPoints > 0 && _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left, he can't be repaired!" << std::endl;
		_hitPoints += amount;
	}
	else if (amount <= 0) {
		std::cout << "Amount has to be positive 😒" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " healed " << amount << " HP!" << std::endl;	
		_hitPoints += amount;
		_energyPoints--;
	}
}
