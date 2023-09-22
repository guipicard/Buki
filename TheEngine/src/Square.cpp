#include "Square.h"
#include "SDL_Graphics.h"
#include "Engine.h"

buki::Square::Square(std::string _name, float _x, float _y, float _h, float _w, const Color& _color)
{
}

void buki::Square::Start()
{
}

void buki::Square::Update(float dt)
{
}

void buki::Square::Render()
{
	RectF myRect{ m_X, m_Y, m_H, m_W };
	buki::Engine::GetInstance().Graphics().DrawRect(myRect, m_Color);
}

void buki::Square::Destroy()
{
}
