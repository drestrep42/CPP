#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << std::endl;

	std::cout << "Turtwig has " << Turtwig.getHitPoints() << " HP and " << Turtwig.getEnergyPoints() << " energy points left." << std::endl;
	std::cout << "Piplup has " << Piplup.getHitPoints() << " HP and " << Piplup.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;

	FragTrap Chimchar("Chimchar");

	std::cout << std::endl;

	Piplup.attack("Chimchar");
	Chimchar.takeDamage(Piplup.getAttackDamage());
	Chimchar.beRepaired(1);
	std::cout << "Chimchar has " << Chimchar.getHitPoints() << " HP and " << Chimchar.getEnergyPoints() << " energy points left." << std::endl;

	std::cout << std::endl;
}
