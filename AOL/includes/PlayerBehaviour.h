#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class PlayerBehaviour : public MonoBehaviour, public Component
	{
	public:
		PlayerBehaviour(Entity* entity);
		~PlayerBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void SetHeart(int value) { m_HeartToCollect = value; }
		Subject<std::string, Entity*> OnHeartPickup;
		Subject<std::string, Entity*> OnKeyPickup;
	private:
		int m_HeartToCollect = 0;
	};
}
