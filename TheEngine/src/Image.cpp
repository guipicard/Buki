#include "Image.h"
#include "SDL_Graphics.h"
#include "Engine.h"

void buki::Image::Start()
{
}

void buki::Image::Draw()
{
	RectF myRect{ 0 };
	Point2D pos = m_Entity->GetPos();
	Point2D size = m_Entity->GetSize();
	myRect.x = pos.x;
	myRect.y = pos.y;
	myRect.h = size.x;
	myRect.w = size.y;
	buki::Engine::GetInstance()->Graphics().DrawTexture(m_Id, myRect, Color::White);
}

void buki::Image::Destroy()
{
}

void buki::Image::SetPath(std::string path)
{
	m_AssetPath = path;
	m_Id = buki::Engine::GetInstance()->Graphics().LoadTexture(m_AssetPath);
}
