#include "HumanB.hpp"

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon!" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}