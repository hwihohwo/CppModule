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
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		virtual std::string getName() const;
		virtual int getHitPoints() const;
		virtual unsigned int getEnergyPoints() const;
		virtual unsigned int getAttackDamage() const;
		virtual void printInfo(void) const;
		void setAttackDamage(unsigned int num);
};

#endif