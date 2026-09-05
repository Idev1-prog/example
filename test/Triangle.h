#pragma once
#include <iostream>

class Triangle {
	float _side;
	float _hight;

public:
	Triangle(): _side(1), _hight(1) {}
	Triangle(float side, float hight) {
		if (side <= 0 || hight <= 0) throw std::invalid_argument("Values cannot be negative or 0");
		_side = side;
		_hight = hight;
	}
	~Triangle() = default;

	void set_side(float side) {
		if (side <= 0) throw std::invalid_argument("Value cannot be negative or 0");
		_side = side;
	}
	void set_hight(float hight) {
		if (hight <= 0) throw std::invalid_argument("Value cannot be negative or 0");
		_hight = hight;
	}

	float get_side() const noexcept {
		return _side;
	}
	float get_hight() const noexcept {
		return _hight;
	}

	float calculate_area() const noexcept {
		return 0.5 * _side * _hight;
	}
};