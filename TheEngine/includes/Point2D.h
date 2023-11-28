#pragma once

namespace buki
{
	struct Point2D
	{
		Point2D() : Point2D(0.0f, 0.0f) {}
		Point2D(float _x, float _y) : x(_x), y(_y) {}
		Point2D(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {}
		Point2D operator-(Point2D sub) { return Point2D(x - sub.x, y - sub.y); }
		void operator-=(Point2D sub) { x = x - sub.x, y = y - sub.y; }
		bool operator!=(Point2D o) { return x != o.x || y != o.y; }
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