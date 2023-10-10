#include "Square.h"
#include "SDL_Graphics.h"
#include "Engine.h"


buki::Square::Square(Entity* _entity) : Component(_entity) 
{
	Point2D size = m_Entity->GetSize();
	m_W = size.x;
	m_H = size.y;
}

void buki::Square::Start()
{
}

void buki::Square::Draw()
{
	RectF myRect;
	Point2D pos = m_Entity->GetPos();
	myRect.x = pos.x + m_X;
	myRect.y = pos.y + m_Y;
	myRect.h = m_H;
	myRect.w = m_W;
	const buki::Color myColor = m_Color;
	buki::Engine::GetInstance()->Graphics().DrawRect(myRect, myColor);
}

void buki::Square::Destroy()
{
	 m_Entity = nullptr;
}
