#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap Turtwig("Turtwig");
	ScavTrap Piplup("Piplup");

	std::cout << std::endl;

	std::cout << "Turtwig has " << Turtwig.getHitPoints() << " HP and " << Turtwig.getEnergyPoints() << " energy points left." << std::endl;
	std::cout << "Piplup has " << Piplup.getHitPoints() << " HP and " << Piplup.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;

	Piplup.attack("Turtwig");
	Turtwig.takeDamage(Piplup.getAttackDamage());
	Turtwig.beRepaired(1);

	std::cout << std::endl;

	std::cout << "Turtwig has " << Turtwig.getHitPoints() << " HP and " << Turtwig.getEnergyPoints() << " energy points left." << std::endl;
	std::cout << "Piplup has " << Piplup.getHitPoints() << " HP and " << Piplup.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;

	Turtwig.attack("Piplup");
	Turtwig.beRepaired(1);

	std::cout << std::endl;
}