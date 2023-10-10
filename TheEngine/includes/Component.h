#pragma once
#include "Entity.h"
#include "IInput.h"

namespace buki
{
	class Component
	{
	private:
		Component() = default;
	public:
		virtual ~Component() {}
		Component(Entity* _entity) : m_Entity(_entity) {}
		virtual void Start() {}
		virtual void Destroy() {}
		buki::IInput& Input() const;
	protected:
		Entity* m_Entity;
	};
}
