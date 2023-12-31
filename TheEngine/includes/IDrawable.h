#pragma once

namespace buki
{
	class IDrawable
	{
	public:
		virtual ~IDrawable() = default;
		virtual void Draw() = 0;
	};
}