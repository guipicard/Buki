#include "Entity.h"
#include "SDL_Graphics.h"
#include "Engine.h"



buki::Entity::Entity()
	: m_X(0)
	, m_Y(0)
	, m_H(0)
	, m_W(0)
	, m_Name("")
	, m_Color(buki::Color::White)
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
}

void buki::Entity::Destroy()
{

}
