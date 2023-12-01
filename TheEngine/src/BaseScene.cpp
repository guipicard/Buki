#include "BaseScene.h"
#include "Engine.h"
#include "Square.h"
#include "Atlas.h"
#include "Entity.h"

buki::BaseScene::BaseScene()
{
}

buki::BaseScene::~BaseScene()
{
}

buki::Entity* buki::BaseScene::Instantiate(const std::string _name)
{
	return buki::Engine::GetInstance().World().Create(_name);
}
