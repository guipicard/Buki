#pragma once
#include "BaseScene.h"
#include "Entity.h"
using namespace buki;


class Entity;
class GameScene : public BaseScene
{
public:
	GameScene();
	virtual void Load() override;
	virtual void Update(float dt) override;
private:
	size_t mumu = size_t();
	size_t sam = size_t();

	buki::Entity* m_Map;

	buki::Entity* m_Player;
};