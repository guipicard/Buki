#pragma once

#include "Component.h"
#include <stack>

enum class Ekey;

namespace buki
{
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
	public:
		void SetAnimation(Animation* _anim) { m_Animation = _anim; }
	private:
		Animation* m_Animation = m_Entity->GetComponent<Animation>();
		std::string m_Direction = "down";
		std::string m_State = "idle";
		std::string m_CurrentAnim = "";
		std::stack<int> m_MoveStack;
		bool m_Lock = false;
	};
}
