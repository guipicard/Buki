#pragma once
#include "Prototypes.h"
#include <cstdlib>
#include <string>
#include <map>

namespace buki {
	struct Spawner : public Component
	{
		Spawner(Entity* entity) {}
		virtual ~Spawner()
		{
			for (auto proto : m_Prototypes)
			{
				delete proto.second;
			}
		}
		virtual void AddPrototype(const std::string& name, Prototypes* proto)
		{
			m_Prototypes[name] = proto;
		}
		virtual Entity* Spawn(const std::string& name, Vector2 position, Vector2 size, float rotation)
		{
			if (m_Prototypes.count(name) > 0)
			{
				return m_Prototypes[name]->Clone(position, size, rotation);
			}
			return nullptr;
		}
	private:
		typedef std::map<std::string, Prototypes*> TProtoMap;
	protected:
		TProtoMap m_Prototypes;
	};
}
