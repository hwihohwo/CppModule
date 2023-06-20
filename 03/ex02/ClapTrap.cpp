#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str)
	: name(str), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "ClapTrap operator assign called" << std::endl;
	return *this;
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

std::string ClapTrap::getName() const
{
	return this->name;
}
int ClapTrap::getHitPoints() const
{
	return this->hit_points;
}
unsigned int ClapTrap::getEnergyPoints() const
{
	return this->energy_points;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->attack_damage;
}

void ClapTrap::setAttackDamage(unsigned int num)
{
	this->attack_damage = num;
}

void ClapTrap::printInfo(void) const
{
	std::cout << "-------" << this->name << "-------" << std::endl;
	std::cout << "name : " << this->name << std::endl;
	std::cout << "hp : " << this->hit_points << std::endl;
	std::cout << "ep : " << this->energy_points << std::endl;
	std::cout << "attack : " << this->attack_damage << std::endl << std::endl;
}