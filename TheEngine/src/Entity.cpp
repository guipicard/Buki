#include "Entity.h"
#include "SDL_Graphics.h"
#include "Engine.h"

buki::Entity::Entity(std::string _name, float _x, float _y, float _h, float _w, const Color& _color)
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
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::RIGHT)))
	{

	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::LEFT)))
	{

	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::UP)))
	{

	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::DOWN)))
	{

	}
}

void buki::Entity::Render()
{
}

void buki::Entity::Destroy()
{

}
