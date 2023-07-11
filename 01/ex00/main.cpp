#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie = new Zombie("link");

	zombie->announce();
	randomChump("zelda");
	delete zombie;
	return 0;
}