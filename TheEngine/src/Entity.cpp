#include "Entity.h"
#include "Atlas.h"

buki::Entity::Entity()
	: Entity("new Entity")
{
}

buki::Entity::Entity(std::string _name)
	: m_Name(_name)
{
	
}

void buki::Entity::Start()
{
	for (auto it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Start();
	}
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
	SetOldPos(Point2D(m_X, m_Y));
	for (auto c : m_Updatable)
	{
		c->Update(dt);
	}
}

void buki::Entity::Destroy()
{
	for (std::multimap<const type_info*, Component*>::iterator it = m_ComponentByType.begin(); it != m_ComponentByType.end(); ++it)
	{
		it->second->Destroy();
		delete it->second;
	}
	m_ComponentByType.clear();
	m_Drawable.clear();
	m_Updatable.clear();
}
