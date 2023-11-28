#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class SnakeyBehaviour : public MonoBehaviour, public Component
	{
	public:
		SnakeyBehaviour(Entity* entity);
		~SnakeyBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void SetPlayer(Entity* player) { m_Player = player; }
		bool GetIsEgg() { return m_IsEgg; }
		void SetEgg();
	private:
		Entity* m_Player = nullptr;
		bool m_IsEgg = false;
	};
}