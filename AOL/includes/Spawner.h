#pragma once
#include "Character.h"
#include <cstdlib>
#include <string>
#include <map>

namespace buki {
	class Spawner
	{
	public:
		virtual ~Spawner() = default;
		//template<typename T>
		//virtual T* AddPrototype(const std::string& name, T* spawner) = 0;
		virtual Entity* Spawn(const std::string& name, int x, int y) = 0;
	};
}
