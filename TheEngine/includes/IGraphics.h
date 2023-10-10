#pragma once
#include <cstdlib>
#include <iostream>
#include "Color.h"

struct RectI
{
	RectI() : RectI(0, 0, 0, 0) {}
	RectI(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}
	int x;
	int y;
	int w;
	int h;
};

struct RectF
{
	RectF() : RectF(0.0f, 0.0f, 0.0f, 0.0f) {}
	RectF(int _x, int _y, int _w, int _h)
		: RectF(static_cast<float>(_x), static_cast<float>(_y), static_cast<float>(_w), static_cast<float>(_h))
	{

	}
	RectF(float _x, float _y, float _w, float _h) : x(_x), y(_y), w(_w), h(_h) {}
	float x;
	float y;
	float w;
	float h;
};

struct Flip
{
	Flip() : Flip(false, false) {}
	Flip(bool _v, bool _h) : v(_v), h(_h) {}
	bool v;
	bool h;
};
namespace buki {


	class IGraphics
	{
	public:
		virtual bool Initialize(const std::string& title, int w, int h) = 0;
		virtual void Shutdown() = 0;
		virtual void SetColor(const Color& color) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void DrawRect(const RectF& rect, const Color& color) = 0;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void FillRect(const RectF& rect, const Color& color) = 0;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
		virtual size_t LoadTexture(const std::string& filename) = 0;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const Color& color) = 0;
		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
		virtual void GetWindowSize(int* w, int* h) = 0;
	};

}