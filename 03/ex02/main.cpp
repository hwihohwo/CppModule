#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap luigi("luigi");
	ScavTrap kupa("kupa");
	ScavTrap mario("mario");
	
	kupa.guardGate();
	mario.attack("kupa");
	kupa.takeDamage(mario.getAttackDamage());
	luigi.attack("kupa");
	kupa.takeDamage(luigi.getAttackDamage());
	for (int i = 0; i < 51; i++)
		kupa.beRepaired(1);
}