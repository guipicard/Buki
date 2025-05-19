#pragma once
#include "Shapes.h"
#include "CircleCollider.h"

namespace buki
{
	struct Circle : public Shapes
	{
		Circle(Entity* entity) : Shapes(entity) {}
		~Circle() = default;

		virtual void Draw(float alpha) override;
		virtual void Start() override;
		virtual void Destroy() override;

		virtual void SetPhysics() override;

		CircleCollider Collider;
	};
}