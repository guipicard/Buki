#pragma once 

namespace buki 
{
	struct RectF
	{
		RectF() : RectF(0.0f, 0.0f, 0.0f, 0.0f) {}
		RectF(int _x, int _y, int _w, int _h) : RectF(static_cast<float>(_x), static_cast<float>(_y), static_cast<float>(_w), static_cast<float>(_h)) {}
		RectF(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}
		float x;
		float y;
		float w;
		float h;
	};
}