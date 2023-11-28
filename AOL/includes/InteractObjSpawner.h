#pragma once
#include "Spawner.h"
#include "InteractObj.h"

namespace buki
{
	class Player;
	class InteractObjSpawner : public Spawner
	{
		typedef std::map<std::string, InteractObj*> TProtoMap;
	public:
		virtual ~InteractObjSpawner()
		{
			for (auto proto : m_Prototypes)
			{
				delete proto.second;
			}
		}
		virtual void AddPrototype(const std::string& name, InteractObj* proto)
		{
			m_Prototypes[name] = proto;
		}
		virtual Entity* Spawn(const std::string& name, int x, int y) override;
	protected:
		TProtoMap m_Prototypes;
	};
}
