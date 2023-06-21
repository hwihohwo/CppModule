#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal* animals[6];
	int i;

	for (i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (; i < 6; i++)
		animals[i] = new Cat();
	
	animals[0]->getBrainValue().ideas[0] = "copied";
	*(Dog*)animals[1] = *(Dog*)animals[0];
	animals[0]->getBrainValue().ideas[0] = "origin";
	
	std::cout << std::endl << animals[0]->getBrainValue().ideas[0] << std::endl;
	std::cout << animals[1]->getBrainValue().ideas[0] << std::endl << std::endl;

	for (i = 0; i < 6; i++)
		delete animals[i];

	system("leaks abstract");
	return 0;
}