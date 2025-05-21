#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap Turtwig("Turtwig");
	ScavTrap Piplup("Piplup");

	std::cout << std::endl;

	Turtwig.attack("Piplup");
	Piplup.takeDamage(5);
	Piplup.beRepaired(1);

	std::cout << std::endl;

	FragTrap Chimchar("Chimchar");

	std::cout << std::endl;

	Piplup.attack("Chimchar");
	Chimchar.takeDamage(5);
	Chimchar.beRepaired(1);
}
