#include "Entity.h"
#include "Component.h"
#include "IGraphics.h"

buki::Entity::Entity()
	: Entity("new Entity", 0.0f, 0.0f, 0.0f, 0.0f)
{
}

buki::Entity::Entity(std::string _name, float _x, float _y, float _w, float _h)
	: m_Name(_name)
	, m_X(_x)
	, m_Y(_y)
	, m_W(_w)
	, m_H(_h)
{
}

buki::Entity::~Entity()
{
	delete& m_ComponentByType;
	delete& m_Drawable;
	delete& m_Updatable;
}

void buki::Entity::Draw()
{
	for (auto c : m_Drawable)
	{
		c->Draw();
	}
}

void buki::Entity::Update(float dt)
{
	for (auto c : m_Updatable)
	{
		c->Update(dt);
	}
}

void buki::Entity::Destroy()
{
	for (std::multimap<const type_info*, Component*>::iterator it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		if (it->second != nullptr)
		{
			it->second->Destroy();
			delete it->second;
			it->second = nullptr;
		}
	}
	m_ComponentByType.clear();
	m_Drawable.clear();
	m_Updatable.clear();
}
