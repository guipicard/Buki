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
		Entity(std::string _name, float _x, float _y, float _h, float _w, const Color& _color);
		~Entity();
		void Start();
		void Update(float dt);
		void Render();
		void Destroy();
		std::string GetName() { return m_Name; }
	protected:
		float m_X;
		float m_Y;
		float m_H;
		float m_W;
		std::string m_Name;
		const Color& m_Color;
	};
}