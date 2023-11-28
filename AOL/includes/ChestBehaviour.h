#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class ChestBehaviour : public MonoBehaviour, public Component
	{
	public:
		ChestBehaviour(Entity* entity);
		~ChestBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
	};
}
