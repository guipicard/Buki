#pragma once
#include "BaseScene.h"

using namespace buki;

class DemoScene : public BaseScene
{
public:
	DemoScene();
	virtual void Load() override;
private:
	Entity* m_Entity1;
	Entity* m_Player;
	size_t mumu = size_t();
	size_t sam = size_t();
};