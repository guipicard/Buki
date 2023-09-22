#pragma once
#include <Entity.h>
struct SDL_Renderer;
namespace buki {
	class Square : public Entity {
	public:
		Square(std::string _name, float _x, float _y, float _h, float _w, const Color& _color);
		void Start();
		void Update(float dt);
		virtual void Render() override;
		void Destroy();


	//private:
		//int m_y = 0;
		//int m_h = 0;
		//int m_w = 0;
	};

}