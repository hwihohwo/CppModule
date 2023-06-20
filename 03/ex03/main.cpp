#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap a("a");
	ScavTrap b("b");
	FragTrap c("c");
	DiamondTrap d("d");
	DiamondTrap e("e");

	a.printInfo();
	b.printInfo();
	c.printInfo();
	d.printInfo();

	b.guardGate();
	std::cout << std::endl;
	c.highFivesGuys();
	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		d.attack("e");
		e.takeDamage(d.getAttackDamage());
		e.beRepaired(20);
	}
	std::cout << std::endl << "d energy : " << d.getEnergyPoints() << std::endl;
}