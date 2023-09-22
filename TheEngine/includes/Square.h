#pragma once
#include <Entity.h>
struct SDL_Renderer;
namespace buki {
	class Square : public Entity {
	public:
		Square(std::string _name, float _x, float _y, float _h, float _w, const Color& _color);
		void Start();
		void Update(float dt);
		void Render();
		void Destroy();
		Point2D GetPos() { return Point2D(m_X, m_Y); }
		void SetPos(Point2D pos) { m_X = pos.x; m_Y = pos.y; }
		Point2D GetSize() { return Point2D(m_H, m_W); }
		void SetSize(Point2D size) { m_H = size.x; m_W = size.y; }

	//private:
		//int m_y = 0;
		//int m_h = 0;
		//int m_w = 0;
	};

}