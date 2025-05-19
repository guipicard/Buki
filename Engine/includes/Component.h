#pragma once
#include "BukiContainers.h"

namespace buki
{
	struct Entity;
	struct IInput;
	struct ILogger;
	struct IGraphics;
	struct IAudio;
	struct ICollision;
	struct IWorld;
	struct IPhysics;

	struct Component
	{
	public:
		virtual ~Component() = default;
		Component();
		Component(Entity* _entity);

		virtual void Start() {}
		virtual void Destroy() {}

		inline Entity* GetEntity() { return m_Entity; }

	protected:
		IInput& Input() const;
		ILogger& Log() const;
		IGraphics& Graphics() const;
		IAudio& Audio() const;
		ICollision& Collision() const;
		IWorld& World() const;
		IPhysics& Physics() const;

		Entity* m_Entity = nullptr;
	};
}
