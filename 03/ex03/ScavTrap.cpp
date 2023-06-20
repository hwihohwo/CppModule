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
{
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << this->name << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	std::cout << this->name << " takes damage! hp decreases " << amount << std::endl;
	this->hit_points -= amount;
	if (this->hit_points <= 0)
		std::cout << this->name << " died!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << this->name << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	else if (this->energy_points == 0)
	{
		std::cout << this->name + " not enough energy" << std::endl;
		return ;
	}
	std::cout << this->name << " repaired for " << amount << std::endl;
	this->hit_points += amount;
	this->energy_points--;
}

std::string ScavTrap::getName() const
{
	return this->name;
}
int ScavTrap::getHitPoints() const
{
	return this->hit_points;
}
unsigned int ScavTrap::getEnergyPoints() const
{
	return this->energy_points;
}

unsigned int ScavTrap::getAttackDamage(void) const
{
	return this->attack_damage;
}

void ScavTrap::printInfo() const
{
	std::cout << "-----ScavTrap info-----" << std::endl;
	std::cout << "name : " << this->name << std::endl;
	std::cout << "hp : " << this->hit_points << std::endl;
	std::cout << "ep : " << this->energy_points << std::endl;
	std::cout << "attack : " << this->attack_damage << std::endl << std::endl;	
}