#pragma once
#include "Component.h"
#include "IDrawable.h"
#include "Color.h"

namespace buki
{
	struct Shapes : public Component, public IDrawable
	{
		Shapes(Entity* entity) { m_Entity = entity; }
		virtual ~Shapes() = default;

		virtual void SetPhysics() = 0;

		bool DebugDraw = false;
		bool DrawShape = false;
		Color ShapeColor = Color();
		Color DebugColor = Color();
	};
}