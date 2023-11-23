#pragma once

#include "Component.h"
#include "Entity.h"
#include <stack>


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
	public:
		void SetAnimation(Animation* _anim) { m_Animation = _anim; }
	private:
		Animation* m_Animation = m_Entity->GetComponent<Animation>();
		std::string m_Direction = "down";
		std::string m_State = "idle";
		std::string m_CurrentAnim = "";
		std::stack<int> m_MoveStack;
		bool m_Lock = false;
		float m_Speed = 50.0f;
	};
}
