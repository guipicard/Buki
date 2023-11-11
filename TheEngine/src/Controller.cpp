#include "Controller.h"
#include "Engine.h"
#include "Animation.h"

buki::Controller::Controller(Entity* _entity) : Component(_entity) {}

void buki::Controller::Start()
{
}

void buki::Controller::Update(float dt)
{
	if (m_Entity->GetComponent<Animation>()->IsStopped())
	{
		buki::Engine::GetInstance()->World().Remove(m_Entity);
	}
	if (m_Lock) return;
	Point2D direction(0, 0);
	if (Input().IsKeyPressed(EKey::UP))
	{
		direction.y -= m_LockY ? 0 : 1;
	}
	if (Input().IsKeyPressed(EKey::DOWN))
	{
		direction.y += m_LockY ? 0 : 1;
	}
	if (Input().IsKeyPressed(EKey::LEFT))
	{
		direction.x -= m_LockX ? 0 : 1;
	}
	if (Input().IsKeyPressed(EKey::RIGHT))
	{
		direction.x += m_LockX ? 0 : 1;
	}

	if (Input().IsKeyDown(EKey::UP))
	{
		m_Direction = "up";
		m_LockX = true;
		m_LockY = false;
	}
	if (Input().IsKeyDown(EKey::DOWN))
	{
		m_Direction = "down";
		m_LockX = true;
		m_LockY = false;
	}
	if (Input().IsKeyDown(EKey::LEFT))
	{
		m_Direction = "left";
		m_LockY = true;
		m_LockX = false;
	}
	if (Input().IsKeyDown(EKey::RIGHT))
	{
		m_Direction = "right";
		m_LockY = true;
		m_LockX = false;
	}



	if (direction.x == 0 && direction.y == 0)
	{
		m_State = "idle";
	}
	else
	{
		m_State = "move";
	}

	Point2D pos = m_Entity->GetPos();
	float speed = m_Entity->GetSpeed();

	pos.x += direction.x * speed * dt;
	pos.y += direction.y * speed * dt;

	m_Entity->SetPos(pos);

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


