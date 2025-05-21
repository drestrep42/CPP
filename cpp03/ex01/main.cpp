#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap Turtwig("Turtwig");
	ClapTrap Piplup("Piplup");

	std::cout << std::endl;

	Turtwig.attack("Piplup");
	Piplup.takeDamage(5);
	Piplup.beRepaired(1);

	std::cout << std::endl;

	ScavTrap Chimchar("Chimchar");

	std::cout << std::endl;

	Piplup.attack("Chimchar");
	Chimchar.takeDamage(5);
	Chimchar.beRepaired(1);
}
