#pragma once

#include "IScene.h"

namespace buki
{
	
	class BaseScene : public IScene
	{
	public:
		BaseScene();
		~BaseScene();
		virtual Entity* Instantiate(const std::string _name) override;
	};
}
