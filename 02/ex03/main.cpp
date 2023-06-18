#include "Point.hpp"

#include <iostream>

int main(void)
{
	Point a(1.0f, 1.0f);
	Point b(4.0f, 4.0f);
	Point c(1.0f, 4.0f);
	Point point1(2.0f, 3.0f);
	Point point2(5.0f, 5.0f);
	Point point3(3.0f, 3.0f);

	bsp(a, b, c, point1) ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	bsp(a, b, c, point2) ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	bsp(a, b, c, point3) ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	bsp(a, b, c, a) ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;

	
	return 0;
}