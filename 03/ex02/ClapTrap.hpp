#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string str);
		ClapTrap(const ClapTrap& obj);
		virtual ClapTrap& operator =(const ClapTrap& obj);
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

		void setAttackDamage(unsigned int num);
		void printInfo(void) const;
};

#endif