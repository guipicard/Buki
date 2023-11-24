#pragma once

namespace buki
{
	class Entity;
	class IInput;
	class ILogger;
	class IGraphics;
	class IAudio;
	class ICollision;
	class IWorld;

	class Component
	{
	public:
		virtual ~Component() = default;
		Component();
		Component(Entity* _entity);

		virtual void Start() {}
		virtual void Destroy() {}

	protected:
		IInput& Input() const;
		ILogger& Log() const;
		IGraphics& Graphics() const;
		IAudio& Audio() const;
		ICollision& Collision() const;
		IWorld& World() const;

		Entity* m_Entity = nullptr;
	};
}
