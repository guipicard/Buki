#include "Square.h"
#include "SDL_Graphics.h"
#include "Engine.h"

void buki::Square::Start()
{
}

void buki::Square::Draw()
{
	RectF myRect{0};
	Point2D pos = m_Entity->GetPos();
	Point2D size = m_Entity->GetSize();
	myRect.x = pos.x;
	myRect.y = pos.y;
	myRect.h = size.x;
	myRect.w = size.y;
	const buki::Color myColor = m_Color;
	buki::Engine::GetInstance()->Graphics().DrawRect(myRect, myColor);
}

void buki::Square::Destroy()
{
	 m_Entity = nullptr;
}
