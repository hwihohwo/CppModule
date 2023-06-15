#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->num = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator = (const Fixed& obj)
{
	if (this == &obj)
		return *this;
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = obj.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->num = raw;
}