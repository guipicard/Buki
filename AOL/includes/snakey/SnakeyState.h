#pragma once
#include <string>

namespace buki
{
	class SnakeyBehaviour;
	class Entity;
	class SnakeyState
	{
	public:
		virtual ~SnakeyState() = default;
		virtual void Start(SnakeyBehaviour* snakey) = 0;
		virtual void Update(float dt, SnakeyBehaviour* snakey) = 0;
		virtual void Exit(SnakeyBehaviour* snakey) = 0;
		virtual void OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey) = 0;
	};
}