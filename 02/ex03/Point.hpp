#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Fixed;

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point();
		Point(const float num1, const float num2);
		Point(const Point& obj);
		~Point();
		Point& operator =(const Point& obj);
		Point operator -(const Point& obj) const;

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif