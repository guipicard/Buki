#pragma once
#include "Character.h"
#include "Prototypes.h"
#include <cstdlib>
#include <string>
#include <map>

namespace buki {
	class Spawner : public Component
	{
		typedef std::map<std::string, Prototypes*> TProtoMap;
	public:
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
		virtual Entity* Spawn(const std::string& name, int x, int y)
		{
			if (m_Prototypes.count(name) > 0)
			{
				return m_Prototypes[name]->Clone(x, y);
			}
			return nullptr;
		}
	protected:
		TProtoMap m_Prototypes;
	};
}
