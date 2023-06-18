#include "Point.hpp"

Point::Point(void) 
	: x(0), y(0) {}

Point::Point(const float num1, const float num2)
	: x(num1), y(num2) {}

Point::Point(const Point& obj)
	: x(obj.x), y(obj.y) {}

Point& Point::operator =(const Point& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

Point Point::operator -(const Point& obj) const
{
	Fixed num1;
	Fixed num2;

	num1 = this->getX() - obj.getX();
	num2 = this->getY() - obj.getY();
	Point ret(num1.toFloat(), num2.toFloat());

	return ret;
}

Point::~Point(void) {}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}