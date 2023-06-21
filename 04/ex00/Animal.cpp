#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.getType();
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator =(const Animal& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.getType();
	std::cout << "Animal assign operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
void Animal::makeSound() const
{
	std::cout << "I don't know what sound to make..." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
