#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	std::cout << std::endl;

	FragTrap	Dialga("Dialga");
	ScavTrap	Palkia("Palkia");
	ClapTrap	Giratina("Giratina");

	std::cout << std::endl;

	DiamondTrap	Torterra("Torterra");

	std::cout << std::endl;

	Torterra.whoAmI();
	std::cout << std::endl;

	std::cout << "FragTrap Dialga has " << Dialga.getHitPoints() << " HP, ";
	std::cout << Dialga.getEnergyPoints() << " EP, ";
	std::cout << Dialga.getAttackDamage() << " AD." << std::endl;

	std::cout << "ScavTrap Palkia has " << Palkia.getHitPoints() << " HP, ";
	std::cout << Palkia.getEnergyPoints() << " EP, ";
	std::cout << Palkia.getAttackDamage() << " AD." << std::endl;

	std::cout << "ClapTrap Giratina has " << Giratina.getHitPoints() << " HP, ";
	std::cout << Giratina.getEnergyPoints() << " EP, ";
	std::cout << Giratina.getAttackDamage() << " AD." << std::endl;

	std::cout << "DiamondTrap Torterra has " << Torterra.getHitPoints() << " HP, ";
	std::cout << Torterra.getEnergyPoints() << " EP, ";
	std::cout << Torterra.getAttackDamage() << " AD." << std::endl;
	std::cout << std::endl;

}
