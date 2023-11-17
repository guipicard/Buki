#include "Controller.h"
#include "Animation.h"

buki::Controller::Controller(Entity* _entity) : Component(_entity) {}

void buki::Controller::Start()
{
}

void buki::Controller::Update(float dt)
{
	if (m_Entity->GetComponent<Animation>()->IsStopped())
	{
		World().Remove(m_Entity);
	}
	if (m_Lock) return;
	Point2D direction(0, 0);

	if (Input().IsKeyDown(EKey::UP))
	{
		m_MoveStack.push(static_cast<int>(EKey::UP));
	}
	if (Input().IsKeyDown(EKey::DOWN))
	{
		m_MoveStack.push(static_cast<int>(EKey::DOWN));
	}
	if (Input().IsKeyDown(EKey::LEFT))
	{
		m_MoveStack.push(static_cast<int>(EKey::LEFT));
	}
	if (Input().IsKeyDown(EKey::RIGHT))
	{
		m_MoveStack.push(static_cast<int>(EKey::RIGHT));
	}

	if (m_MoveStack.empty())
	{
		m_State = "idle";
	}
	else
	{
		m_State = "move";
		switch (m_MoveStack.top()) {
		case static_cast<int>(EKey::UP):
			if (Input().IsKeyPressed(EKey::UP))
			{
				direction.y -= 1;
				m_Direction = "up";
			}
			else
			{
				m_MoveStack.pop();
			}
			break;
		case static_cast<int>(EKey::DOWN):
			if (Input().IsKeyPressed(EKey::DOWN))
			{
				direction.y += 1;
				m_Direction = "down";
			}
			else
			{
				m_MoveStack.pop();
			}
			break;
		case static_cast<int>(EKey::LEFT):
			if (Input().IsKeyPressed(EKey::LEFT))
			{
				direction.x -= 1;
				m_Direction = "left";
			}
			else
			{
				m_MoveStack.pop();
			}
			break;
		case static_cast<int>(EKey::RIGHT):
			if (Input().IsKeyPressed(EKey::RIGHT))
			{
				direction.x += 1;
				m_Direction = "right";
			}
			else
			{
				m_MoveStack.pop();
			}
			break;
		}
		Point2D pos;
		m_Entity->GetPosition(&pos);

		pos.x += direction.x * m_Speed * dt;
		pos.y += direction.y * m_Speed * dt;

		m_Entity->SetPos(pos);
	}

	if (m_Animation != nullptr)
	{
		std::string animName = m_State + "_" + m_Direction;
		if (animName != m_CurrentAnim)
		{
			m_Animation->Play(animName, true);
			m_CurrentAnim = animName;
		}
	}
}

void buki::Controller::Destroy()
{
}


