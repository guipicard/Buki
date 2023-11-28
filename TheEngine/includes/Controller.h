#pragma once
#include "Component.h"
#include "Entity.h"
#include <queue>


namespace buki
{
	enum class Ekey;
	class Animation;

	class Controller : public Component, public IUpdatable
	{
	public:
		Controller(Entity* _entity);
		virtual ~Controller() = default;

		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Destroy()  override;
		void LockController() { m_Lock = true; }
		void SetSpeed(float _speed) { m_Speed = _speed; }
		void SetAnimation(Animation* _anim) { m_Animation = _anim; }
		void StopMoving();
	private:
		void StopMoving(int key);
		Animation* m_Animation = m_Entity->GetComponent<Animation>();
		std::string m_Direction = "down";
		std::string m_State = "idle";
		std::string m_CurrentAnim = "";
		std::queue<int> m_MoveStack;
		bool m_Lock = false;
		bool m_Moving = false;
		float m_Speed = 0.0f;
		Point2D m_Start;
		Point2D m_End;
		Point2D m_Velocity;
		float m_Distance = 16.0f;
	};
}
