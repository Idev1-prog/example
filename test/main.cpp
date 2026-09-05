#include <iostream>

#include "Triangle.h"
int main() {
	Triangle triangle;
	float a, h;
	std::cout << "Enter the width and height (example: 1 3): ";
	std::cin >> a >> h;
	triangle.set_hight(h);
	triangle.set_side(a);
	std::cout << "Area: " << triangle.calculate_area();
	return 0;
}