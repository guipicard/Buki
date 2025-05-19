#pragma once
#include "IScene.h"

namespace buki
{
	
	struct BaseScene : public IScene
	{
	public:
		BaseScene();
		~BaseScene();
		virtual Entity* Instantiate(const std::string _name) override;
		virtual void OnStart() override;
		virtual void OnStop() override;
	};
}
