#pragma once
#include "WorldService.h"
#include "Engine.h"
#include "box2d.h"
#include "Entity.h"
#include "BaseScene.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "RigidBody.h"
#include "CircleCollider.h"
#include "MonoBehaviour.h"
#include "Text.h"
#include <algorithm>
#include <unordered_set>

buki::WorldService::WorldService()
{
	Start();
}

void buki::WorldService::Start()
{

}

void buki::WorldService::FixedUpdate(float dt)
{
	WorldId wId = Engine::GetInstance().Physics().GetPhysicsWorld();
	b2WorldId b2wId = b2WorldId{ wId.index, wId.revision };
	b2World_Step(b2wId, dt, 8);
	for (int i = static_cast<int>(m_EntityInWorld.size()) - 1; i > 0; i--)
	{
		Entity* e = m_EntityInWorld[i];
		if (e->HasPhysics())
		{
			Transform* et = e->GetTransform();
			BodyId bId = e->GetBodyId();
			b2BodyId b2Id = b2BodyId{ bId.index1, bId.world0, bId.revision };
			b2Vec2 pos = b2Body_GetPosition(b2Id);
			b2Rot rot = b2Body_GetRotation(b2Id);
			et->SetPosition(Vector2{ pos.x, pos.y });
			et->SetRotation(Rot{ rot.c, rot.s });
		}
		e->FixedUpdate(dt);
	}
}

void buki::WorldService::Update(float dt)
{
	for (int i = static_cast<int>(m_EntityInWorld.size()) - 1; i > 0; i--)
	{
		m_EntityInWorld[i]->Update(dt);
	}
	CleanEntities();
	if (m_SceneToLoad != "")
	{
		Load(m_SceneToLoad);
	}
}

void buki::WorldService::Render(float alpha)
{
	for (auto entity : m_EntityInWorld)
	{
		entity->Draw(alpha);
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
	m_Name = "";
	m_SceneToLoad = "";
	m_ScenesByName.clear();
	delete& m_EntityMap;
	delete& m_EntityInWorld;
	delete& m_EntityToRemove;
	delete& m_Scenes;
	delete& m_ScenesByName;
	m_CurrentScene = nullptr;
}

void buki::WorldService::Add(Entity* _entity)
{
	m_EntityMap.emplace(_entity->GetName(), _entity);
	m_EntityInWorld.push_back(_entity);
	SortEntities();
}

void buki::WorldService::Remove(Entity* _entity)
{
	m_EntityToRemove.emplace_back(_entity);
}

buki::Entity* buki::WorldService::Find(std::string _name)
{
	return m_EntityMap[_name];
}

std::vector<buki::Entity*> buki::WorldService::FindAll(std::string _name)
{
	std::vector<Entity*> list = std::vector<Entity*>();
	for each(auto obj in m_EntityInWorld)
	{
		if (obj->GetName() == _name)
		{
			list.push_back(obj);
		}
	}
	return list;
}

void buki::WorldService::Load(const std::string& scene) {
	if (m_Scenes.count(scene) > 0)
	{
		Unload();
		m_CurrentScene = m_Scenes[scene];
		SetCurrentSceneName(scene);
		m_CurrentScene->OnStart();
		m_CurrentScene->Load();
	}
	else
	{
		Unload();
		m_CurrentScene = m_Scenes["Menu"];
		SetCurrentSceneName("Menu");
		m_CurrentScene->OnStart();
		m_CurrentScene->Load();
	}
	m_SceneToLoad = "";
}

void buki::WorldService::SetLoadScene(const std::string& scene)
{
	m_SceneToLoad = scene;
}

void buki::WorldService::Unload()
{
	CleanEntities();
	Engine::GetInstance().Physics().Reset();
	if (m_CurrentScene != nullptr)
	{
		m_CurrentScene->OnStop();
		for (auto entity : m_EntityInWorld)
		{
			if (entity != nullptr)
			{
				entity->Destroy();
				delete entity;
				entity = nullptr;
			}
		}
		m_EntityMap.clear();
		m_EntityInWorld.clear();
		m_EntityToRemove.clear();
	}
}

void buki::WorldService::Register(const std::string& name, IScene* scene)
{
	if (m_Scenes.count(name) == 0)
	{
		m_ScenesByName.push_back(name);
		m_Scenes[name] = scene;
	}
}

buki::Entity* buki::WorldService::Create(const std::string& name)
{
	Entity* _e = new Entity(name);
	Add(_e);
	return _e;
}

void buki::WorldService::LoadNextScene()
{
	int index = -1;
	for (int i = 0; i < m_ScenesByName.size(); i++)
	{
		if (m_ScenesByName[i] == m_Name)
		{
			index = i + 1;

		}
	}
	if (index > m_ScenesByName.size() - 1)
	{
		SetLoadScene("Menu");
	}
	if (index != -1) SetLoadScene(m_ScenesByName[index]);
}

static bool SortPairs(buki::Collider* lhs, buki::Collider* rhs)
{
	return true;
}

void buki::WorldService::IntegrateForces(Entity* e, float dt)
{
}

void buki::WorldService::IntegrateVelocity(Entity* e, float dt)
{
}

void buki::WorldService::GeneratePairs(float dt, Vector2 gravity)
{
}

void buki::WorldService::CheckCollisions(Manifold* M, float dt, Vector2 gravity)
{
}


void buki::WorldService::SortEntities()
{
	std::vector<std::vector<Entity*>> lists = std::vector<std::vector<Entity*>>();
	std::map<int, std::vector<Entity*>> zMap = std::map<int, std::vector<Entity*>>();
	for each(Entity * entity in m_EntityInWorld)
	{
		zMap[entity->GetZ()].push_back(entity);
	}
	size_t layers = zMap.size();
	m_EntityInWorld.clear();
	for (int i = 0; i < layers; i++)
	{
		m_EntityInWorld.insert(m_EntityInWorld.end(), zMap[i].begin(), zMap[i].end());
	}
}

void buki::WorldService::CleanEntities()
{
	if (m_EntityToRemove.size() > 0)
	{
		std::vector<Entity*> _trash = m_EntityToRemove;

		for (auto entity : _trash)
		{
			if (entity->HasPhysics())
			{
				BodyId bId = entity->GetBodyId();
				b2BodyId b2Id = b2BodyId{ bId.index1, bId.world0, bId.revision };
				b2DestroyBody(b2Id);
			}
			std::map<std::string, Entity*>::iterator it = m_EntityMap.begin();
			while (it != m_EntityMap.end())
			{
				if (it->second == entity)
				{
					m_EntityMap.erase(it);
					break;
				}
				it++;
			}

			for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); it++)
			{
				if (entity == *it)
				{
					m_EntityInWorld.erase(it);
					break;
				}
			}

			entity->Destroy();
			delete entity;
		}
		_trash.clear();
		m_EntityToRemove.clear();
	}
}
