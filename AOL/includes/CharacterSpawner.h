#pragma once
#include "Spawner.h"
#include "Character.h"

namespace buki
{
	class Player;
	class CharacterSpawner : public Spawner
	{
	public:
		~CharacterSpawner() = default;
		void SetPrototype(Character* proto) {
			m_Prototype = proto;
		}
		Character* Spawn() {
			return m_Prototype->Clone();
		}
	private:
		Character* m_Prototype = nullptr;

	};
}
