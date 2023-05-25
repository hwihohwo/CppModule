#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name)
{
	this->name = name;
	std::cout << this->name + " turns into zombie!" << std::endl;
}