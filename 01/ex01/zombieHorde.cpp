#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombiehorde;

	if (N < 0)
		return (NULL);
	zombiehorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombiehorde[i].setZombieName(name);
	return (zombiehorde);
}