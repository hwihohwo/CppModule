#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria* on_field[100];

	for (int i = 0; i < 100; i++)
		on_field[i] = NULL;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	Character* me = new Character("me");
	ICharacter* me_copy = new Character("me_copy");

	*me_copy = *me;
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("test");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me_copy->equip(tmp);
	tmp = src->createMateria("ice");
	me_copy->equip(tmp);
	tmp = src->createMateria("test");
	me_copy->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	std::cout << "copy use" << std::endl;
	me_copy->use(0, *bob);
	me_copy->use(1, *bob);
	me_copy->use(2, *bob);
	std::cout << "copy use end" << std::endl;

	on_field[0] = me->inventory[0];
	me->unequip(0);
	on_field[1] = me->inventory[1];
	me->unequip(1);
	on_field[2] = me->inventory[2];
	me->unequip(2);

	me->equip(on_field[1]);
	on_field[1] = NULL;
	me->use(0, *bob);

	delete bob;
	delete me;
	delete me_copy;
	delete src;

	for (int i = 0; i < 100; i++)
	{
		if (on_field[i])
			delete on_field[i];
	}
	return 0;
}