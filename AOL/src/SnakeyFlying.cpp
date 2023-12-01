#include "SnakeyFlying.h"
#include "SnakeyBehaviour.h"
#include "Engine.h"
#include "Entity.h"
#include "BulletsBehaviour.h"

buki::SnakeyFlying::SnakeyFlying()
{
	m_Speed = 500.0f;
	m_Velocity = Point2D();
}

void buki::SnakeyFlying::Start(SnakeyBehaviour* snakey)
{
	m_Speed = 500.0f;
	
}

void buki::SnakeyFlying::Update(float dt, SnakeyBehaviour* snakey)
{
	if (m_Velocity != Point2D())
	{
		Point2D pos, size;
		snakey->GetEntity()->GetPosition(pos);
		snakey->GetEntity()->GetSize(size);
		snakey->GetEntity()->SetPos(pos + (m_Velocity * m_Speed * dt));
		int x, y;
		Engine::GetInstance().Graphics().GetWindowSize(&x, &y);
		if (pos.x < -size.x || pos.x > static_cast<float>(x) || pos.y < -size.y || pos.y > static_cast<float>(y))
		{
			snakey->SetState("out");
		}
	}
}

void buki::SnakeyFlying::Exit(SnakeyBehaviour* snakey)
{
}

void buki::SnakeyFlying::OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey)
{
	if (value == "playerBullets")
	{
		m_Velocity = other->GetComponent<BulletsBehaviour>()->GetVelocity();
		Engine::GetInstance().World().Remove(other);
	}
}
