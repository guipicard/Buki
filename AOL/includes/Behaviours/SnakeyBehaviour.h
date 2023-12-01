#pragma once
#include "MonoBehaviour.h"
#include "SnakeyState.h"

namespace buki
{
	class SnakeyBehaviour : public MonoBehaviour, public Component
	{
	public:
		SnakeyBehaviour(Entity* entity);
		~SnakeyBehaviour();
		void SetState(const std::string& state);
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void SetPlayer(Entity* player) { m_Player = player; }
		Entity* GetEntity() { return m_Entity; }
		Entity* GetPlayer() { return m_Player; }
		void ReSpawn();
	private:
		SnakeyState* m_CurrentState = nullptr;
		std::map<std::string, SnakeyState*> m_States;
		Point2D m_StartPos;
		Entity* m_Player = nullptr;
	};
}