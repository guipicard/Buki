#pragma once
#include "SnakeyState.h"

namespace buki
{
	class SnakeyOut : public SnakeyState
	{
	public:
		SnakeyOut();
		virtual void Start(SnakeyBehaviour* snakey) override;
		virtual void Update(float dt, SnakeyBehaviour* snakey) override;
		virtual void Exit(SnakeyBehaviour* snakey) override;
		virtual void OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey) override;
	private:
		float m_Timer;
		float m_Elapsed;
	};
}