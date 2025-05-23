#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Turtwig("Turtwig");
	ClapTrap Piplup("Piplup");

	std::cout << std::endl;

	std::cout << "Turtwig has " << Turtwig.getHitPoints() << " HP and " << Turtwig.getEnergyPoints() << " energy points left." << std::endl;
	std::cout << "Piplup has " << Piplup.getHitPoints() << " HP and " << Piplup.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;

	Turtwig.attack("Piplup");
	Piplup.takeDamage(Turtwig.getAttackDamage());
	Piplup.beRepaired(1);

	std::cout << std::endl;

	std::cout << "Turtwig has " << Turtwig.getHitPoints() << " HP and " << Turtwig.getEnergyPoints() << " energy points left." << std::endl;
	std::cout << "Piplup has " << Piplup.getHitPoints() << " HP and " << Piplup.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;

	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.attack("Piplup");
	Turtwig.beRepaired(10);

	std::cout << std::endl;
}
