#include "Entity.h"
#include "SDL_Graphics.h"
#include "Engine.h"

buki::Entity::Entity(std::string _name, int _x, int _y, int _h, int _w, const Color& _color)
	: m_Name(_name)
	, m_X(_x)
	, m_Y(_y)
	, m_H(_h)
	, m_W(_w)
	, m_Color(_color)
{
}

buki::Entity::~Entity()
{
}

void buki::Entity::Start()
{
}

void buki::Entity::Update(float dt)
{
}

void buki::Entity::Render()
{
	RectF myRect{ m_X, m_Y, m_H, m_W };
	buki::Engine::GetInstance().Graphics().DrawRect(myRect, m_Color);
}

void buki::Entity::Destroy()
{
}
