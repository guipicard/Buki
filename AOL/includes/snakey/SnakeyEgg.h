#pragma once
#include "SnakeyState.h"
#include "Point2D.h"

namespace buki
{
	class SnakeyBehaviour;
	class Entity;
	class SnakeyEgg : public SnakeyState
	{
	public:
		SnakeyEgg();
		virtual void Start(SnakeyBehaviour* snakey) override;
		virtual void Update(float dt, SnakeyBehaviour* snakey) override;
		virtual void Exit(SnakeyBehaviour* snakey) override;
		virtual void OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey) override;
		void Move(Entity* other, SnakeyBehaviour* snakey);
	private:
		float m_Timer;
		float m_Elapsed;
		float m_Speed;
		Point2D m_Velocity;
		
	};
}
