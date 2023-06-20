#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	protected:
		int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		ScavTrap();
		ScavTrap(std::string str);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator =(const ScavTrap& obj);
		~ScavTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		void printInfo(void) const;
		void guardGate();
};

#endif