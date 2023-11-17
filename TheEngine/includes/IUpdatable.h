#pragma once

namespace buki 
{
	class IUpdatable
	{
	public:
		virtual void Update(float dt) = 0;
	};
}