#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = ClapTrap::name;
	ClapTrap::name = this->name + "_clap_name";
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string str)
	: ClapTrap(str)
{
	this->name = ClapTrap::name;
	ClapTrap::name = this->name + "_clap_name";
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
	std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "DiamondTrap copy constrcutor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator =(const DiamondTrap& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_damage = obj.getAttackDamage();
	std::cout << "DiamondTrap assign operator called" << std::endl;
	return *this;
}


DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::printInfo() const
{
	std::cout << "-----DiamondTrap info-----" << std::endl;
	std::cout << "name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
	std::cout << "hp : " << this->hit_points << std::endl;
	std::cout << "ep : " << this->energy_points << std::endl;
	std::cout << "attack : " << this->attack_damage << std::endl << std::endl;	
}

void DiamondTrap::attack(const std::string& target)
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

void DiamondTrap::takeDamage(unsigned int amount)
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

void DiamondTrap::beRepaired(unsigned int amount)
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

std::string DiamondTrap::getName() const
{
	return this->name;
}
int DiamondTrap::getHitPoints() const
{
	return this->hit_points;
}
unsigned int DiamondTrap::getEnergyPoints() const
{
	return this->energy_points;
}

unsigned int DiamondTrap::getAttackDamage(void) const
{
	return this->attack_damage;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}