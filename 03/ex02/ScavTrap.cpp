#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string str)
	: ClapTrap(str)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " + this->getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
	: ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "ScavTrap assign operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " + this->name << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	else if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " + this->name + " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " + this->name << " is now in GateKeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " + this->name << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	else if (this->energy_points == 0)
	{
		std::cout << "ScavTrap " + this->name + " not enough energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " + this->name << " attacks " << target << std::endl;
	this->energy_points--;
}