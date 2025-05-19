#pragma once
#include "BaseScene.h"
#include "Entity.h"
#include "Subject.h"
#include "Observer.h"
#include "Button.h"
#include "Component.h"
#include <string>

namespace buki
{
	struct Entity;
	struct MenuScene : public BaseScene, Observer<std::string>
	{
		MenuScene();
		virtual void Load() override;
		virtual void OnWindowResize() override;
		virtual void OnNotify(const std::string& button) override;
	};
}