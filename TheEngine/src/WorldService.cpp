#include "WorldService.h"

buki::WorldService::~WorldService()
{
	for each (auto entity in m_EntityInWorld)
	{
		Remove(entity);
		entity->Destroy();
		delete entity;
	}
	delete &m_EntityMap;
}

void buki::WorldService::Start()
{

}

void buki::WorldService::Update(float dt)
{
	for (auto entity : m_EntityInWorld) 
	{
		entity->Update(dt);
	}

}

void buki::WorldService::Render()
{
	for (auto entity : m_EntityInWorld) 
	{
		entity->Render();
	}
}

void buki::WorldService::Destroy()
{

}

void buki::WorldService::Add(Entity* _entity)
{
	m_EntityInWorld.push_back(_entity);
	m_EntityMap.emplace(_entity->GetName(), _entity);

}

void buki::WorldService::Remove(Entity* _entity)
{
	for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it)
	{
		if (*it == _entity)
		{
			break;
		}
			m_EntityMap.erase(_entity->GetName());
	}
}

void buki::WorldService::Find()
{

}
