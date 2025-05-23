#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
	
		~ClapTrap();

		ClapTrap(const ClapTrap& copy);
		virtual ClapTrap&	operator=(const ClapTrap& copy);

		virtual std::string	getName() const;
		virtual int			getHitPoints() const;
		virtual int			getEnergyPoints() const;
		virtual int			getAttackDamage() const;

		virtual void		attack(const std::string& target);
		virtual void		takeDamage(unsigned int amount);
		virtual void		beRepaired(unsigned int amount);
};

#endif
