#pragma once
#include "BaseScene.h"

using namespace buki;

namespace buki
{
	class Entity;
	class Tilemap;
	class Animation;
	class Controller;
	class Spawner;
	class GameScene : public BaseScene
	{
	public:
		GameScene();
		virtual void Load() override;
		virtual void Update(float dt) override;
	private:
		size_t mumu = size_t();
		size_t sam = size_t();


		Entity* m_Map = nullptr;
		Tilemap* m_Tilemap = nullptr;
	};
}