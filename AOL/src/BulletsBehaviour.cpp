#include "BulletsBehaviour.h"
#include "Engine.h"
#include "Atlas.h"
#include "SnakeyBehaviour.h"

buki::BulletsBehaviour::BulletsBehaviour(Entity* entity)
	: Component(entity)
{
}

void buki::BulletsBehaviour::Update(float dt)
{
	Point2D pos;
	m_Entity->GetPosition(pos);

	pos.x += m_Velocity.x * m_Speed * dt;
	pos.y += m_Velocity.y * m_Speed * dt;
	m_Entity->SetPos(pos);
	if (m_Start.Distance(pos) > m_Distance)
	{
		World().Remove(m_Entity);
	}
}

void buki::BulletsBehaviour::OnNotify(const std::string& value, Entity* other)
{
}

void buki::BulletsBehaviour::SetDirection(std::string direction)
{
	if (direction == "up")
	{
		m_Velocity = Point2D(0.0f, -1.0f);
	}
	else if (direction == "right")
	{
		m_Velocity = Point2D(1.0f, 0.0f);
	}
	else if (direction == "down")
	{
		m_Velocity = Point2D(0.0f, 1.0f);
	}
	else if (direction == "left")
	{
		m_Velocity = Point2D(-1.0f, 0.0f);
	}
	m_Entity->GetComponent<Atlas>()->SetFrame(direction);
}
