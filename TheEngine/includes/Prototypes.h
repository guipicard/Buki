#pragma once
#include "Entity.h"

namespace buki
{
	class Prototypes
	{
	public:
		virtual Entity* Clone(int x, int y) = 0;
	};
}