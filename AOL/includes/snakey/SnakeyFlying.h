#pragma once
#include "SnakeyState.h"
#include "Point2D.h"

namespace buki
{
	class SnakeyBehaviour;
	class Entity;
	class SnakeyFlying : public SnakeyState
	{
	public:
		SnakeyFlying();
		virtual void Start(SnakeyBehaviour* snakey) override;
		virtual void Update(float dt, SnakeyBehaviour* snakey) override;
		virtual void Exit(SnakeyBehaviour* snakey) override;
		virtual void OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey) override;
	private:
		float m_Speed;
		Point2D m_Velocity;
	};
}