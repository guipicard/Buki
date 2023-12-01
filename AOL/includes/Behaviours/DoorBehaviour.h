#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class DoorBehaviour : public MonoBehaviour
	{
	public:
		DoorBehaviour(Entity* entity);
		~DoorBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
	};
}
