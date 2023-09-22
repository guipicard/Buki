#pragma once

namespace buki
{
	class IScene
	{
	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
		virtual void Load2() = 0;
	};
}
