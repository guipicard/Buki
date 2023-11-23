#pragma once
#include <string>

namespace buki
{
	class Entity;
	class IScene
	{
	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
		virtual void Update(float dt) = 0;
		virtual Entity* Instantiate(const std::string _name) = 0;
	};
}
