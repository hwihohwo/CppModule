#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;

	public:
		ClapTrap(std::string str);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getAttackDamage();
		void setAttackDamage(const unsigned int num);
};

#endif