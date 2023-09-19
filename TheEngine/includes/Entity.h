#pragma once
#include "IGraphics.h"

namespace buki
{
	class Entity
	{
	public:
		Entity(std::string _name, int _x, int _y, int _h, int _w, const Color& _color);
		~Entity();
		void Start();
		void Update(float dt);
		void Render();
		void Destroy();
		std::string GetName() { return m_Name; }
	private:
		int m_X;
		int m_Y;
		int m_H;
		int m_W;
		std::string m_Name;
		const Color& m_Color;
	};
}