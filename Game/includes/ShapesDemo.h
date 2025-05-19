#pragma once
#include "BaseScene.h"
#include "Subject.h"
#include "Observer.h"

using namespace buki;

namespace buki
{
	struct Entity;
	struct Spawner;
	struct Sprite;
	struct Atlas;
	struct ShapesDemo : public BaseScene, Observer<std::string>
	{
		ShapesDemo();
		virtual void Load() override;
		virtual void OnWindowResize() override;
		virtual void OnNotify(const std::string& button) override;
	private:
		void GroundAndBackground();
		Entity* Ground;
		Atlas* GroundSprite;
		Entity* Background;
		Atlas* BackgroundImage;
	};
}
