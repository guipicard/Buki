#pragma once
#include "Entity.h"
#include "Engine.h"
#include "Prototypes.h"

namespace buki
{
	class Bullet : public Prototypes
	{
	public:
		Bullet(int speed, float distance) : m_Speed(speed), m_Distance(distance) {}
		virtual ~Bullet() = default;
	protected:
		int m_Speed;
		float m_Distance;
	};
}