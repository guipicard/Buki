#pragma once
#include "Entity.h"
#include "Prototypes.h"

namespace buki
{
	class Character : public Prototypes
	{
	public:
		Character(int speed) : m_Speed(speed){}
		virtual ~Character() = default;
	protected:
		int m_Speed;
	};
}
