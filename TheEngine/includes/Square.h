#pragma once
#include <Entity.h>
struct SDL_Renderer;
namespace buki {
	class Square : public Entity {
	public:
		Square(std::string _name, float _x, float _y, float _h, float _w, const Color& _color);
		virtual void Start() override;
		virtual void Update(float dt)  override;
		virtual void Render() override;
		virtual void Destroy()  override;
	};

}