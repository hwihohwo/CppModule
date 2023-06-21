#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	this->type = obj.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator =(const WrongCat& obj)
{
	if (this == &obj)
		return *this;
	this->type = obj.getType();
	std::cout << "WrongCat assign operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "woof woof~~" << std::endl;
}