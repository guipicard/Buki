#pragma once
#include "Collider.h"

namespace buki
{
	class BoxCollider : public Collider, public Component
	{
	public:
		BoxCollider(Entity* entity);
		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void CheckTileCollision() override;
		virtual void CheckCollision() override;
	};
}
