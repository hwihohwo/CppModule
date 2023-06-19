#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string str)

{
	std::cout << "ScavTrap " + this->getName() << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " + this->getName() << " is now in GateKeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " + this->getName() << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	else if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " + this->getName() + " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " + this->getName() << " attacks " << target << std::endl;
	this->DecreaseEnergyPoint();
}