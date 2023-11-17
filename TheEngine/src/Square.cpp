#include "Square.h"
#include "SDL_Graphics.h"
#include "Engine.h"


buki::Square::Square(Entity* _entity) : Component(_entity) 
{
	Point2D size;
	m_Entity->GetSize(&size);
	m_W = size.x;
	m_H = size.y;
}

void buki::Square::Start()
{
}

void buki::Square::Draw()
{
	RectF myRect;
	Point2D pos;
	m_Entity->GetPosition(&pos);
	m_Entity->GetRect(&myRect);
	myRect.x += m_X;
	myRect.y += m_Y;
	const buki::Color myColor = m_Color;
	Graphics().DrawRect(myRect, myColor);
}

void buki::Square::Destroy()
{
	 m_Entity = nullptr;
}
