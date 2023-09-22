#pragma once
#include "IGraphics.h"




namespace buki
{

	struct Point2D
	{
		Point2D(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
		int x;
		int y;
	};

	class Entity
	{
	public:
		Entity();
		~Entity();
		void Start();
		virtual void Update(float dt);
		virtual void Render() = 0;;
		void Destroy();
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