#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
	: name(str), hit_points(100), energy_points(50), attack_damage(20)
{
	std::cout << this->name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap desturctor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << this->name << " attacks " << target << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
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

void ClapTrap::beRepaired(unsigned int amount)
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

unsigned int ClapTrap::getAttackDamage(void)
{
	return this->attack_damage;
}

void ClapTrap::setAttackDamage(const unsigned int num)
{
	this->attack_damage = num;
}

std::string& ClapTrap::getName()
{
	return this->name;
}

int ClapTrap::getHitPoints()
{
	return this->hit_points;
}

unsigned int ClapTrap::getEnergyPoints()
{
	return this->energy_points;
}

void ClapTrap::DecreaseEnergyPoint()
{
	this->energy_points--;
}