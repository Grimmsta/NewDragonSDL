#pragma once
#include "Engine.h"

struct Bounds {

	Bounds() {}
	Bounds(int x, int y, int width, int height ) : height(height), y(y), width(width), x(x) {}

	int height, y, width, x;

	bool CollidesWith(const Bounds& other) const {
		return other.x < x + width && other.x + other.width > x &&
			other.y <y + height && other.y + other.height > y;
	}
};
