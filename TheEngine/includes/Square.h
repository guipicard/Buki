#pragma once
#include "Component.h"
#include "Color.h"

struct SDL_Renderer;
namespace buki
{
	class Square : public Component, public IDrawable
	{
	public:
		Square(Entity* _entity);
		virtual ~Square() = default;
		virtual void Start() override;
		virtual void Draw() override;
		virtual void Destroy()  override;
		const Color GetColor() { return m_Color; }
		Square* SetColor(Color _color) { m_Color = _color; return this; }
		Square* SetOffset(float _x, float _y) { m_X = _x; m_Y = _y; return this; }
		Square* SetSize(float _w, float _h) { m_W = _w; m_H = _h; return this; }
	private:
		Color m_Color = Color::White;
		float m_X = 0.0f;
		float m_Y = 0.0f;
		float m_W = 0.0f;
		float m_H = 0.0f;
	};
}
