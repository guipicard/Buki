#include "Controller.h"
#include "Engine.h"

void buki::Controller::Start()
{
}

void buki::Controller::Update(float dt)
{
	if (buki::Engine::GetInstance()->Input().IsKeyPressed(static_cast<int>(EKey::UP)))
	{
		Point2D pos = m_Entity->GetPos();
		pos.y -= m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (buki::Engine::GetInstance()->Input().IsKeyPressed(static_cast<int>(EKey::DOWN)))
	{
		Point2D pos = m_Entity->GetPos();
		pos.y += m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (buki::Engine::GetInstance()->Input().IsKeyPressed(static_cast<int>(EKey::LEFT)))
	{
		Point2D pos = m_Entity->GetPos();
		pos.x -= m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (buki::Engine::GetInstance()->Input().IsKeyPressed(static_cast<int>(EKey::RIGHT)))
	{
		Point2D pos = m_Entity->GetPos();
		pos.x += m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
}

void buki::Controller::Destroy()
{
}
