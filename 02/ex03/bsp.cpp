#include "Point.hpp"

Fixed CrossProduct(const Point& vector1, const Point& vector2)
{
	return (vector1.getX() * vector2.getY() - vector1.getY() * vector2.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const Point vertices[3] = {a, b, c};
	int sign[3];
	Fixed	value;

	for (int i = 0; i < 3; i++)
	{
		Point vector1 = point - vertices[i];
		Point vector2 = point - vertices[(i + 1) % 3];
		value = CrossProduct(vector1, vector2);
		sign[i] = value > 0 ? 1 : \
				  value == 0 ? 0 : -1;
	}
	if (sign[0] == sign[1] &&\
		sign[1] == sign[2] &&\
		sign[2] == sign[0])
		return true;
	else
		return false;
}