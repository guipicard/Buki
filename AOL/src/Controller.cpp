#include "Controller.h"
#include "Animation.h"
#include "Ekey.h"
#include "IInput.h"
//#include "ICollision.h"
#include <math.h>
#include <Tilemap.h>
#include <PlayerBehaviour.h>
#include <Engine.h>

buki::Controller::Controller(Entity* _entity) : Component(_entity) {}

void buki::Controller::Start()
{
}

void buki::Controller::Update(float dt)
{
	if (Input().IsKeyDown(EKey::EKEY_X))
	{
		m_Entity->GetComponent<PlayerBehaviour>()->Shoot(m_AnimDirection);
	}
	if (Input().IsKeyDown(EKey::EKEY_LEFTSHIFT))
	{
		Die();
	}
	Move(dt);
	Animate();
}

void buki::Controller::Destroy()
{
}

void buki::Controller::Move(float dt)
{
	if (m_Lock) return;

	if (Input().IsKeyDown(EKey::EKEY_UP))
	{
		m_MoveStack.push(static_cast<int>(EKey::EKEY_UP));
	}
	if (Input().IsKeyDown(EKey::EKEY_DOWN))
	{
		m_MoveStack.push(static_cast<int>(EKey::EKEY_DOWN));
	}
	if (Input().IsKeyDown(EKey::EKEY_LEFT))
	{
		m_MoveStack.push(static_cast<int>(EKey::EKEY_LEFT));
	}
	if (Input().IsKeyDown(EKey::EKEY_RIGHT))
	{
		m_MoveStack.push(static_cast<int>(EKey::EKEY_RIGHT));
	}

	if (m_MoveStack.empty())
	{
		m_State = "idle";
	}
	else if (!m_Moving)
	{
		m_Moving = true;
		m_State = "move";
		m_Entity->GetPosition(m_Start);
		m_End = m_Start;
		switch (m_MoveStack.front()) {
		case static_cast<int>(EKey::EKEY_UP):
			m_Direction.y -= 1;
			m_AnimDirection = "up";
			m_End.y -= m_Distance;
			break;
		case static_cast<int>(EKey::EKEY_DOWN):
			m_Direction.y += 1;
			m_AnimDirection = "down";
			m_End.y += m_Distance;
			break;
		case static_cast<int>(EKey::EKEY_LEFT):
			m_Direction.x -= 1;
			m_AnimDirection = "left";
			m_End.x -= m_Distance;
			break;
		case static_cast<int>(EKey::EKEY_RIGHT):
			m_Direction.x += 1;
			m_AnimDirection = "right";
			m_End.x += m_Distance;
			break;
		}
	}
	else
	{
		Point2D pos;
		m_Entity->GetPosition(pos);

		 m_Velocity.x = m_Direction.x * m_Speed * dt;
		 m_Velocity.y = m_Direction.y * m_Speed * dt;
		 pos += m_Velocity;
		if (m_Start.Distance(pos) > m_Distance)
		{
			pos = m_End;
			StopMoving(m_MoveStack.front());
		}
		m_Entity->SetPos(pos);
	}
}

void buki::Controller::Animate()
{
	if (m_Animation != nullptr)
	{
		std::string animName = m_State + "_" + m_AnimDirection;
		if (animName != m_CurrentAnim)
		{
			m_Animation->Play(animName, true);
			m_CurrentAnim = animName;
		}
	}
}

void buki::Controller::Die()
{
	LockController();
	m_Entity->GetComponent<Animation>()->Play("death", false);
}

void buki::Controller::StopMoving()
{
	m_Moving = false;
	m_Velocity = Point2D();
	m_Direction = Point2D();
	if (m_MoveStack.size() > 0) m_MoveStack.pop();
	Point2D pos;
	m_Entity->GetOldPos(pos);
	pos.x = round(pos.x / 16.0f) * 16.0f;
	pos.y = round(pos.y / 16.0f) * 16.0f;
	m_Entity->SetPos(pos);
	Log().LogMessage(std::to_string(pos.x));
}

void buki::Controller::StopMoving(int key)
{
	if (!Input().IsKeyPressed(static_cast<EKey>(key)))
	{
		if (m_MoveStack.size() > 0) m_MoveStack.pop();
	}
	m_Moving = false;
	m_Velocity = Point2D();
	m_Direction = Point2D();
}
