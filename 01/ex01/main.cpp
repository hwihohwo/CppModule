#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombiehorde;

	zombiehorde = zombieHorde(Znum, "A dog");
	for (int i = 0; i < Znum; i++)
		zombiehorde[i].announce();
	delete[] zombiehorde;
	return 0;
}