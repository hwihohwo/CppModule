#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type = obj.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator =(const Dog& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.getType();
	std::cout << "Dog assign operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof woof!" << std::endl;
}