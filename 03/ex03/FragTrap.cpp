#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string str)
	: ClapTrap(str)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " + this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator =(const FragTrap& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "FragTrap assign operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap " + this->name << " does not response. Maybe just trash can" << std::endl;
		return ;
	}
	else if (this->energy_points == 0)
	{
		std::cout << "FragTrap " + this->name + " not enough energy" << std::endl;
		return ;
	}
	std::cout << "Nicely done guys! highFives!" << std::endl;
}

void FragTrap::attack(const std::string& target)
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

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
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

std::string FragTrap::getName() const
{
	return this->name;
}
int FragTrap::getHitPoints() const
{
	return this->hit_points;
}
unsigned int FragTrap::getEnergyPoints() const
{
	return this->energy_points;
}

unsigned int FragTrap::getAttackDamage(void) const
{
	return this->attack_damage;
}

void FragTrap::printInfo() const
{
	std::cout << "-----FragTrap info-----" << std::endl;
	std::cout << "name : " << this->name << std::endl;
	std::cout << "hp : " << this->hit_points << std::endl;
	std::cout << "ep : " << this->energy_points << std::endl;
	std::cout << "attack : " << this->attack_damage << std::endl << std::endl;	
}