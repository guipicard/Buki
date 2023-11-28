#pragma once
#include "Collider.h"

namespace buki
{
	class CircleCollider : public Collider, public Component
	{
	public:
		CircleCollider(Entity* entity);
		virtual void Update(float dt) override;
		virtual void Draw() override;
		virtual void CheckCollision() override;
		void SetOldPos();
	private:
		
	};
}
