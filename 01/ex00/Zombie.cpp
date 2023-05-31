#include "Zombie.hpp"

void Zombie::announce(void)
{
	if (this->name)
		std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	if (this->name)
		std::cout << this->name + " turns into zombie!" << std::endl;
}

Zombie::~Zombie()
{
	if (this->name)
		std::cout << this->name + " destroyed!" << std::endl;
}