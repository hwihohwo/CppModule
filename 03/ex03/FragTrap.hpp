#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	protected:
		int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		FragTrap();
		FragTrap(std::string str);
		FragTrap(const FragTrap& obj);
		FragTrap& operator =(const FragTrap& obj);
		~FragTrap();

		void highFivesGuys(void) const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		void printInfo(void) const;
};

#endif