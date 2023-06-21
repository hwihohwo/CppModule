#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& obj)
{
	this->type = obj.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator =(const Cat& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.getType();
	std::cout << "Cat assign operator callled" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meow meow~" << std::endl;
}