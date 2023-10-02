#pragma once

#include "Component.h"
#include "SDL_Graphics.h"

struct SDL_Renderer;
namespace buki
{
	class Square : public Component, public IDrawable
	{
	public:
		Square() : Square(nullptr) {};
		Square(Entity* _entity) { m_Entity =_entity; };
		virtual ~Square() = default;
		virtual void Start() override;
		virtual void Draw() override;
		virtual void Destroy()  override;
		void SetColor(Color _color) { m_Color = _color; }
	private:
		buki::Color m_Color = buki::Color::White;
	};
}
