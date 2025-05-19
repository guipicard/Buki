#pragma once
#include "Shapes.h"
#include "BoxCollider.h"

namespace buki
{
	struct Box : public Shapes
	{
		Box(Entity* entity) : Shapes(entity) {}
		~Box() = default;

		virtual void Draw(float alpha) override;
		virtual void Start() override;
		virtual void Destroy() override;

		virtual void SetPhysics() override;


		BoxCollider Collider;
	};
}