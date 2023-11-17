#pragma once

namespace buki
{
	struct Point2D
	{
		Point2D() : Point2D(0.0f, 0.0f) {}
		Point2D(float _x, float _y) : x(_x), y(_y) {}
		float x;
		float y;
	};
}