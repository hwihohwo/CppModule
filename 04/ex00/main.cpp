#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat* i2 = new Cat();
	const WrongAnimal* k = new WrongCat();
	const WrongAnimal* l = new WrongAnimal();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;

	i->makeSound();
	i2->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	l->makeSound();

	delete meta;
	delete j;
	delete i;
	delete i2;
	delete k;
	delete l;

	return 0;
}