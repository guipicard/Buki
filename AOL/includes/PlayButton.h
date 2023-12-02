#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"

namespace buki
{
	class PlayButton : public Component, public IUpdatable, public IDrawable
	{
	public:
		PlayButton(Entity* entity);
		~PlayButton();
		virtual void Update(float dt) override;
		virtual void Draw() override;
	private:
		bool m_Draw = false;
	};
}