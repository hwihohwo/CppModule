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

Fixed::Fixed(const int integer)
{
	this->num = integer << Fixed::getBitWidth();
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_num)
{
	this->num = roundf(float_num * Fixed::ft_pow_(2, Fixed::getBitWidth()));
	std::cout << "Float constructor called" << std::endl;
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
	return this->num;
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

int Fixed::getBitWidth(void)
{
	return Fixed::bit_width;
}

float Fixed::toFloat(void) const
{
	float ret;

	ret = (float)this->num;
	ret /= Fixed::ft_pow_(2, Fixed::getBitWidth());
	return ret;
}

int Fixed::toInt(void) const
{
	int ret;

	ret = this->num >> Fixed::getBitWidth();
	return ret;
}

int Fixed::ft_pow_(const int num, const int pow)
{
	int i;
	int ret;

	ret = 1;
	for (i = 0; i < pow; i++)
		ret *= num;
	return ret;
}

std::ostream& operator <<(std::ostream& outputStream, const Fixed& num)
{
	int integer;
	float fraction;
	int fraction_mask;

	fraction_mask = 0;
	for (int i = 0; i < Fixed::getBitWidth(); i++)
		fraction_mask += Fixed::ft_pow_(2, i);
	integer = num.getRawBits() >> Fixed::getBitWidth();
	fraction = num.getRawBits() & fraction_mask;
	fraction /= Fixed::ft_pow_(2, Fixed::getBitWidth());
	std::cout << integer + fraction;
	return outputStream;
}