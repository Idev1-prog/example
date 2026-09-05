#include <iostream>
void main() {
	double a, h, S;
	std::cout << "Enter the width and height (example: 1 3): ";
	std::cin >> a >> h;
	S = 0.5 * a * h;
	std::cout << "Area: ";
	std::cout << S;
}