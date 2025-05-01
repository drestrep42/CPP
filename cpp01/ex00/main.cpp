#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie = newZombie("Norberto");
	zombie->announce();
	delete zombie;

	randomChump("Eustaquio");
}
