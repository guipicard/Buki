#pragma once
#include "BaseScene.h"
#include "Point2D.h"

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
	private:
		size_t mumu = size_t();
		size_t sam = size_t();

		Point2D m_SpawnPoint;
	};
}
