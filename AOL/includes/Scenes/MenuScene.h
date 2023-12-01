#pragma once
#include "BaseScene.h"
#include "Entity.h"
using namespace buki;


class Entity;
class MenuScene : public BaseScene
{
public:
	MenuScene();
	virtual void Load() override;
	virtual void Update(float dt);
private:
};