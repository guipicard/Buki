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

	struct AGLevel1 : public BaseScene, Observer<std::string>
	{
		AGLevel1();
		virtual void Load() override;
		virtual void OnWindowResize() override;
		virtual void OnNotify(const std::string& button) override;
		virtual void OnStart() override;
		virtual void OnStop() override;
	private:
		void GroundAndBackground();
		void InitLevel();
		void SpawnSlignshot(float _offset);
		void CreateLevelMenu();
		Entity* Ground;
		Atlas* GroundSprite;
		Entity* Background;
		Atlas* BackgroundImage;
		Spawner* spawner;
		Entity* Controller;
		Entity* slignshot1;
		Entity* slignshot2;
		std::string currentLevel = "";
	};
}