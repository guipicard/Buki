#include "WorldService.h"

buki::WorldService::~WorldService()
{
	for each (auto entity in m_EntityInWorld)
	{
		Remove(entity);
		entity->Destroy();
		delete entity;
	}
	delete& m_EntityMap;
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
	Unload();
	
	for (std::map<std::string, IScene*>::iterator it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
	{
		if (it->second != nullptr)
		{
			delete it->second;
			it->second = nullptr;
		}
	}
	delete& m_Scenes;
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

void buki::WorldService::Load(const std::string& scene) {
	if (m_Scenes.count(scene) > 0)
	{
		Unload();
		m_CurrentScene = m_Scenes[scene];
		if (scene == "Menu")
		{
			m_CurrentScene->Load();
		}
		else if (scene == "NotMenu")
		{
			m_CurrentScene->Load2();
		}
	}
}

void buki::WorldService::Unload() {
	if (m_CurrentScene != nullptr)
	{
		for (auto entity : m_EntityInWorld)
		{
			entity->Destroy();
			delete entity;
		}
		m_EntityInWorld.clear();
		m_EntityMap.clear();
	}
}

void buki::WorldService::Register(const std::string& name, IScene* scene) {
	if (m_Scenes.count(name) == 0)
	{
		m_Scenes[name] = scene;
	}
}


