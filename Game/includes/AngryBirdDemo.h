#pragma once
#include "BaseScene.h"
#include "BukiContainers.h"
#include <cstdlib>
#include <map>
#include <vector>
#include "Observer.h"


namespace buki
{
	struct Entity;
	struct Sprite;
	struct Atlas;
	struct Spawner;

	struct AngryBirdDemo : public BaseScene, Observer<std::string>
	{
		AngryBirdDemo();
		virtual void Load() override;
		virtual void OnWindowResize() override;
		virtual void OnNotify(const std::string& button) override;
		virtual void OnStart() override;
		virtual void OnStop() override;
	private:
		void CreateMenu();
		Entity* Background;
		Atlas* BackgroundImage;
		Spawner* spawner;
	};
}