#pragma once

#include "IScene.h"
#include "Entity.h"

namespace buki
{
	
	class DemoScene : public IScene
	{
	public:
		DemoScene();
		~DemoScene();
		virtual void Load() override;
	private:
		Entity* m_Entity1;
	};
}