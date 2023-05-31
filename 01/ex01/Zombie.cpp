#include "Zombie.hpp"

void Zombie::announce(void)
{
	if (this->name)
		std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string name)
{
	this->name = name;
	if (this->name)
		std::cout << this->name + " turns into zombie!" << std::endl;
}