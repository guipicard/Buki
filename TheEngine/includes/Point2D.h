#pragma once
#include "math.h"

namespace buki
{
	struct Point2D
	{
		Point2D() : Point2D(0.0f, 0.0f) {}
		Point2D(float _x, float _y) : x(_x), y(_y) {}
		Point2D(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {}
		bool operator==(Point2D eq) { return x == eq.x && y == eq.y; }
		Point2D operator-(Point2D sub) { return Point2D(x - sub.x, y - sub.y); }
		Point2D operator+(Point2D add) { return Point2D(x + add.x, y + add.y); }
		void operator+=(Point2D add) { x += add.x, y += add.y; }
		Point2D operator*(float mul) { return Point2D(x * mul, y * mul); }
		Point2D operator*(Point2D mul) { return Point2D(x * mul.x, y * mul.y); }
		void operator*=(Point2D mul) {  x *= mul.x, y *= mul.y; }
		void operator-=(Point2D sub) { x = x - sub.x, y = y - sub.y; }
		bool operator!=(Point2D o) { return x != o.x || y != o.y; }
		Point2D operator/(float o) { return Point2D(x / o, y / o); }
		void operator/=(float o) { x /= o; y /= o; }
		Point2D operator/(Point2D o) { return Point2D(x / o.x, y / o.y); }
		Point2D Abs() { return Point2D(x = abs(x), y = abs(y)); }

		float Distance(Point2D other)
		{
			double distance = sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
			float distanceFloat = static_cast<float>(distance);
			return distanceFloat;
		}
		float x;
		float y;
	};
}