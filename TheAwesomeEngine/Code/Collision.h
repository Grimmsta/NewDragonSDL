#pragma once

/* An axis-aligned bounding box (AABB), with some collision math */
struct engBoundingBox {
	engBoundingBox(): x(0), y(0), width(0), height(0)
	{}

	engBoundingBox(int x, int y, unsigned int width, unsigned int height): x(x), y(y), width(width), height(height)
	{}

	int x;
	int y;
	int width;
	int height;

	// Returns if this bounding box intersects the other
	bool CollidesWith(const engBoundingBox& Other) const
	{
		return Other.x < x + width && Other.x + Other.width > x &&
			Other.y < y + height && Other.y + Other.height > y;
	}
};