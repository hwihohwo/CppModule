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
	: ClapTrap(obj)
{
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