#include "Controller.h"
#include "Engine.h"

buki::Controller::Controller(Entity* _entity) : Component(_entity) {}

void buki::Controller::Start()
{
}

void buki::Controller::Update(float dt)
{
	if (Input().IsKeyPressed(EKey::UP))
	{
		Point2D pos = m_Entity->GetPos();
		pos.y -= m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (Input().IsKeyPressed(EKey::DOWN))
	{
		Point2D pos = m_Entity->GetPos();
		pos.y += m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (Input().IsKeyPressed(EKey::LEFT))
	{
		Point2D pos = m_Entity->GetPos();
		pos.x -= m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
	if (Input().IsKeyPressed(EKey::RIGHT))
	{
		Point2D pos = m_Entity->GetPos();
		pos.x += m_Entity->GetSpeed() * dt;
		m_Entity->SetPos(pos);
	}
}

void buki::Controller::Destroy()
{
}


