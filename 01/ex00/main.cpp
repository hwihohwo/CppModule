#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie = new Zombie("link");

	randomChump("zelda");
	delete zombie;
	return 0;
}