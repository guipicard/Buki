#pragma once
#include "IScene.h"
#include "Entity.h"
namespace buki
{

	class PremoScene : public IScene
	{
	public:
		PremoScene();
		~PremoScene();
		virtual void Load() override;
	private:
		Entity* m_Entity1;
	};
}
