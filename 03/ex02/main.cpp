#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("a");
	FragTrap b("b");
	ClapTrap c("c");
	ScavTrap d("d");

	a.printInfo();
	b.printInfo();
	c.printInfo();
	d.printInfo();
	for (int i = 0; i < 6; i++)
	{
		a.attack("b");
		b.takeDamage(a.getAttackDamage());
		b.beRepaired(10);
	}
	a.highFivesGuys();
}