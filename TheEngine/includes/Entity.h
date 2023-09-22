#pragma once
#include "IGraphics.h"

namespace buki
{

	struct Point2D
	{
		Point2D() : Point2D(0, 0) {}
		Point2D(int _x, int _y) : Point2D(static_cast<float>(_x), static_cast<float>(_y)) {}
		Point2D(float _x, float _y) : x(_x), y(_y) {}
		float x;
		float y;
	};

	class Entity
	{
	public:
		virtual ~Entity() = default;
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void Destroy() = 0;

		std::string GetName() { return m_Name; }
		Point2D GetPos() { return Point2D(m_X, m_Y); }
		void SetPos(Point2D pos) { m_X = pos.x; m_Y = pos.y; }
		Point2D GetSize() { return Point2D(m_H, m_W); }
		void SetSize(Point2D size) { m_H = size.x; m_W = size.y; }

	protected:
		float m_X;
		float m_Y;
		float m_H;
		float m_W;
		std::string m_Name;
		Color m_Color;
	};
}
