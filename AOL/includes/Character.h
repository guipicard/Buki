#pragma once
#include "Entity.h"
#include "cstdlib" 
#include <string> 

namespace buki
{
	class Character
	{
	public:
		Character(int speed, int x, int y) : m_Speed(speed), m_X(x), m_Y(y) {}
		virtual ~Character() = default;
		virtual Character* Clone() = 0;
	protected:
		int m_Speed;
		int m_X;
		int m_Y;
	};
}
