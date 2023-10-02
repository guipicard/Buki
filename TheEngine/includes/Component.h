#pragma once

#include "IUpdatable.h"
#include "IDrawable.h"

namespace buki
{
	class Entity;
	class Component
	{
	public:
		virtual ~Component() {}
		Component() : Component(nullptr) {}
		Component(Entity* _entity) : m_Entity(_entity) {}
		virtual void Start() {}
		virtual void Destroy() {}
	protected:
		Entity* m_Entity;
	};
}
