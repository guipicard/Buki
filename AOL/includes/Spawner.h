#pragma once
#include "Character.h"
#include <cstdlib>
#include <string>
#include <map>

namespace buki {
	class Spawner
	{
		typedef std::map<std::string, Character*> TProtoMap;
	public:
		~Spawner() = default;
		void AddPrototype(const std::string& name, Character* proto)
		{
			m_Prototypes[name] = proto;
		}
		Character* Spawn(const std::string& name)
		{
			if (m_Prototypes.count(name) > 0)
			{
				return m_Prototypes[name]->Clone();
			}
			return nullptr;
		}
	private:
		TProtoMap m_Prototypes;
	};
}
