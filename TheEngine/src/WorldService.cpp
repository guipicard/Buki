#include "WorldService.h"
#include "Engine.h"

buki::WorldService::~WorldService()
{
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
	if (buki::Engine::GetInstance().Input().IsKeyDown(EKey::EKEY_RETURN))
	{
		if (m_CurrentScene == m_Scenes["Menu"])
		{
			Load("Game");
		}
		else
		{
			Load("Menu");
		}
	}

}

void buki::WorldService::Render()
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Draw();
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
	delete& m_EntityInWorld;
	delete& m_EntityMap;
	delete& m_Scenes;
}

void buki::WorldService::Add(Entity* _entity)
{
	m_EntityInWorld.push_back(_entity);
	m_EntityMap.emplace(_entity->GetName(), _entity);
}

void buki::WorldService::Remove(Entity* _entity)
{

	m_EntityMap.erase(_entity->GetName());
	m_EntityInWorld.erase(std::remove(m_EntityInWorld.begin(), m_EntityInWorld.end(), _entity), m_EntityInWorld.end());
	if (_entity != nullptr)
	{
		_entity->Destroy();
		delete _entity;
		_entity = nullptr;
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
		SetCurrentSceneName(scene);
		m_CurrentScene->Load();
	}
}

void buki::WorldService::Unload()
{
	if (m_CurrentScene != nullptr)
	{
		m_EntityMap.clear();
		for (auto entity : m_EntityInWorld)
		{
			if (entity != nullptr)
			{
				entity->Destroy();
				delete entity;
				entity = nullptr;
			}
		}
		m_EntityInWorld.clear();
	}
}

void buki::WorldService::Register(const std::string& name, IScene* scene)
{
	if (m_Scenes.count(name) == 0)
	{
		m_Scenes[name] = scene;
	}
}

buki::Entity* buki::WorldService::Create(const std::string& name)
{
	return Create(name, 0.0f, 0.0f, 1.0f, 1.0f);
}

buki::Entity* buki::WorldService::Create(const std::string& name, float _x, float _y, float _w, float _h)
{
	Entity* _e = new Entity(name);
	_e->SetPos(Point2D(_x, _y));
	_e->SetPos(Point2D(_w, _h));
	Add(_e);
	return _e;
}
