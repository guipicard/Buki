#pragma once
#include "IWorld.h"

namespace buki
{
	class WorldService : public IWorld
	{
	public:
		virtual ~WorldService() override;
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Render() override;
		virtual void Destroy() override;
		virtual void Add(Entity* _entity) override;
		virtual void Remove(Entity* _entity) override;
		virtual void Find() override;
		virtual void Load(const std::string& scene) override;
		virtual void Unload() override;
		virtual void Register(const std::string& name, IScene* scene) override;
		virtual IScene* GetCurrentScene() override { return m_CurrentScene; }
		virtual void SetCurrentSceneName(std::string _name) override { m_Name = _name; }
		virtual std::string GetCurrentSceneName() override { return m_Name; }
		Entity* Create(const std::string& name) override;
		Entity* Create(const std::string& name, float _x, float _y, float _h, float _w) override;

	private:
		std::string m_Name;
		std::map<std::string, Entity*> &m_EntityMap = *new std::map<std::string, Entity*>();
		std::vector<Entity*> &m_EntityInWorld = *new std::vector<Entity*>();
		std::map<std::string, IScene*> &m_Scenes = *new std::map<std::string, IScene*>();
		IScene* m_CurrentScene = nullptr;
	};
}
