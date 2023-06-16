#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->num = 0;
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed::Fixed(const int integer)
{
	this->num = integer << Fixed::getBitWidth();
}

Fixed::Fixed(const float float_num)
{
	this->num = roundf(float_num * Fixed::ft_pow_(2, Fixed::getBitWidth()));
}

Fixed::~Fixed(void)
{
	
}

Fixed& Fixed::operator =(const Fixed& obj)
{
	if (this == &obj)
		return *this;
	this->num = obj.getRawBits();
	return *this;
}

bool Fixed::operator <(const Fixed& obj)
{
	return this->num < obj.getRawBits();
}

bool Fixed::operator >(const Fixed& obj)
{
	return this->num > obj.getRawBits();
}

bool Fixed::operator <=(const Fixed& obj)
{
	return this->num <= obj.getRawBits();
}

bool Fixed::operator >=(const Fixed& obj)
{
	return this->num >= obj.getRawBits();
}

bool Fixed::operator ==(const Fixed& obj)
{
	return this->num == obj.getRawBits();
}

bool Fixed::operator !=(const Fixed& obj)
{
	return this->num != obj.getRawBits();
}

Fixed Fixed::operator +(const Fixed& obj)
{
	Fixed ret;

	ret.setRawBits(this->num + obj.getRawBits());
	return ret;
}

Fixed Fixed::operator -(const Fixed& obj)
{
	Fixed ret;

	ret.setRawBits(this->num - obj.getRawBits());
	return ret;
}

Fixed Fixed::operator *(const Fixed& obj)
{
	Fixed ret;

	ret.setRawBits(this->num * obj.getRawBits());
	ret.setRawBits(ret.getRawBits() >> Fixed::getBitWidth());
	return ret;
}

Fixed Fixed::operator /(const Fixed& obj)
{
	Fixed ret;

	ret.setRawBits((this->getRawBits() << Fixed::getBitWidth()) / obj.getRawBits());
	return ret;
}

Fixed& Fixed::operator ++()
{
	this->num += 1;
	return *this;
}

Fixed Fixed::operator ++(int)
{
	Fixed temp(*this);
	this->num += 1;
	return temp;
}

Fixed& Fixed::operator --()
{
	this->num -= 1;
	return *this;
}

Fixed Fixed::operator --(int)
{
	Fixed temp(*this);
	this->num -= 1;
	return temp;
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

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1 < num2) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits()) ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1 > num2) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits()) ? num1 : num2;
}

std::ostream& operator <<(std::ostream& outputStream, const Fixed& num)
{
	std::cout << num.toFloat();
	return outputStream;
}
