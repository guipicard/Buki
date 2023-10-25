#pragma once
#include "Entity.h"
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IAudio.h"

namespace buki
{
	class Component
	{
	private:
		Component() = default;
	public:
		virtual ~Component() {}
		Component(Entity* _entity);
		virtual void Start() {}
		virtual void Destroy() {}
		virtual IInput& Input() const;
		virtual ILogger& Log() const;
		virtual IGraphics& Graphics() const;
		virtual IAudio& Audio() const;

	protected:
		Entity* m_Entity;
	};
}
