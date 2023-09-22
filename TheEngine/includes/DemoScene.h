#pragma once

#include "IScene.h"

namespace buki
{

	class DemoScene : public IScene
	{
	public:
		virtual void Load() override;
		virtual void Load2() override;
	};
}
