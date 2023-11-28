#pragma once
#include "Entity.h"

namespace buki
{
	class InteractObj
	{
	public:
		InteractObj() {}
		virtual ~InteractObj() = default;
		virtual Entity* Clone(int x, int y) = 0;
	protected:
		
	};
}