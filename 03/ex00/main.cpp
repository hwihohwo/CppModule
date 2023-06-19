#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap jack("jack");
	ClapTrap wattson("wattson");

	jack.attack("wattson");
	wattson.takeDamage(jack.getAttackDamage());
	wattson.attack("jack");
	jack.takeDamage(wattson.getAttackDamage());

	jack.setAttackDamage(10);
	jack.attack("wattson");
	wattson.takeDamage(jack.getAttackDamage());

	for (int i = 0; i < 10; i++)
		jack.beRepaired(0);
	wattson.attack("jack");
}