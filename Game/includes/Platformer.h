#pragma once
#include "BaseScene.h"

namespace buki
{
	struct Atlas;
	struct Entity;
	struct Platformer : public BaseScene
	{
		Platformer();
		virtual void Load() override;
		virtual void OnWindowResize() override;
	private:
		void GroundAndBackground();
		Entity* Ground;
		Atlas* GroundAtlas;
		Entity* Background;
		Atlas* BackgroundAtlas;
	};
}