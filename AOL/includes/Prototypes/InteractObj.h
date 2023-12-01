#pragma once
#include "Entity.h"
#include "Prototypes.h"

namespace buki
{
	class InteractObj : public Prototypes
	{
	public:
		InteractObj() {}
		virtual ~InteractObj() = default;
		virtual Entity* Clone(int x, int y) = 0;
	};
}
