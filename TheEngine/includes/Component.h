#pragma once
#include "Entity.h"
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IAudio.h"
#include "ICollision.h"
#include "IWorld.h"

namespace buki
{
	class Component
	{
	public:
		virtual ~Component() = default;
		Component();
		Component(Entity* _entity);

		virtual void Start() {}
		virtual void Destroy() {}

	protected:
		virtual IInput& Input() const;
		virtual ILogger& Log() const;
		virtual IGraphics& Graphics() const;
		virtual IAudio& Audio() const;
		virtual ICollision& Collision() const;
		virtual IWorld& World() const;

		Entity* m_Entity = nullptr;
	};
}
