#pragma once
#include "SnakeyState.h"

namespace buki
{
	class SnakeyBehaviour;
	class Entity;
	class SnakeyIdle : public SnakeyState
	{
	public:
		SnakeyIdle();
		virtual void Start(SnakeyBehaviour* snakey) override;
		virtual void Update(float dt, SnakeyBehaviour* snakey) override;
		virtual void Exit(SnakeyBehaviour* snakey) override;
		virtual void OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey) override;
	};
}