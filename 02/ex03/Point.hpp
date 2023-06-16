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
}

#endif