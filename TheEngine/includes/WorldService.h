#pragma once
#include "IWorld.h"
#include <map>
#include <vector>

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
	private:
		std::map<std::string, Entity*> &m_EntityMap = *new std::map<std::string, Entity*>();
		std::vector<Entity*> m_EntityInWorld;
	};
}