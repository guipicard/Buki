#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class PlayerBehaviour : public MonoBehaviour
	{
	public:
		PlayerBehaviour(Entity* entity);
		~PlayerBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void SetHeart(int value) { m_HeartToCollect = value; }
		Subject<std::string, Entity*> OnHeartPickup;
		Subject<std::string, Entity*> OnKeyPickup;
		void Shoot(std::string direction);
	private:
		int m_Charges = 0;
		int m_HeartToCollect = 0;
		bool m_DoorOpened = false;
	};
}
