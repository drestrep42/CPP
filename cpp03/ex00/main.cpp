#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Turtwig("Turtwig");
	ClapTrap Piplup("Piplup");

	Turtwig.attack("Piplup");
	Piplup.takeDamage(5);
	Piplup.beRepaired(1);
}
