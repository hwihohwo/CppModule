#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie = newZombie("link");

	randomChump("zelda");
	delete zombie;
	return 0;
}