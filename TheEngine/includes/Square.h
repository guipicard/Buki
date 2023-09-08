#pragma once
#include "IShape.h"
struct SDL_Renderer;
namespace buki {
	class Square : public IShape {
	public:
		Square(float _x, float _y, float _h, float _w, SDL_Renderer* _renderer);
		virtual ~Square() = default;
		virtual void Draw() override;
		virtual void SetPosition(float x, float y) override;
		virtual float GetPosX() { return m_x; }
		virtual float GetPosY() { return m_y; }
	private:
		SDL_Renderer* m_Renderer;
		float m_x = 0.0f; 
		float m_y = 0.0f; 
		float m_h = 0.0f;
		float m_w = 0.0f;
	};

}