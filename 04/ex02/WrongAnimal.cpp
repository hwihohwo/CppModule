#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->type = obj.getType();
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.getType();
	std::cout << "WrongAnimal assign operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm wrong animal..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}