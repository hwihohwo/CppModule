#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = new Weapon(weapon.getType());
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void)
{
	if (this->weapon)
		delete this->weapon;
}