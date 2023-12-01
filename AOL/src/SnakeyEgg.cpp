#include "SnakeyEgg.h"
#include "Atlas.h"
#include "SnakeyBehaviour.h"
#include "Entity.h"
#include "Controller.h"
#include "Engine.h"
#include "BoxCollider.h"
#include "Atlas.h"
#include "Animation.h"
#include "BulletsBehaviour.h"

buki::SnakeyEgg::SnakeyEgg()
{
	m_Timer = 10.0f;
	m_Elapsed = 0.0f;
	m_Speed = 0.0f;
	m_Velocity = Point2D();
}

void buki::SnakeyEgg::Start(SnakeyBehaviour* snakey)
{
	snakey->GetEntity()->GetComponent<Atlas>()->SetFrame("egg");
	m_Timer = 10.0f;
	m_Elapsed = 0.0f;
	m_Speed = 0.0f;
	m_Velocity = Point2D();
}

void buki::SnakeyEgg::Update(float dt, SnakeyBehaviour* snakey)
{
	m_Elapsed += dt;
	if (m_Elapsed > m_Timer)
	{
		snakey->GetEntity()->GetComponent<Atlas>()->SetFrame("cracked");
		if (m_Elapsed > m_Timer + 2.0f)
		{
			snakey->GetEntity()->GetComponent<Animation>()->Play("respawn", false);
			snakey->SetState("idle");
		}
	}
}

void buki::SnakeyEgg::Exit(SnakeyBehaviour* snakey)
{
}

void buki::SnakeyEgg::OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey)
{
	if (value == "playerBullets")
	{
		snakey->SetState("flying");
	}
	if (value == "player")
	{
		Move(other, snakey);
	}
}

void buki::SnakeyEgg::Move(Entity* other, SnakeyBehaviour* snakey)
{
	Point2D pos, playerPos, playerOldPos, playerVelocity, diffrence, newPos;
	snakey->GetEntity()->GetPosition(pos);
	snakey->GetPlayer()->GetPosition(playerPos);
	playerVelocity = snakey->GetPlayer()->GetComponent<Controller>()->GetVelocity();
	snakey->GetPlayer()->GetOldPos(playerOldPos);
	diffrence = playerOldPos - playerPos;
	newPos = pos - diffrence;
	snakey->GetEntity()->SetPos(newPos);
	if (snakey->GetEntity()->GetComponent<BoxCollider>()->CheckTileCollision())
	{
		Engine::GetInstance().Log().LogMessage("move");
		Point2D oldPos;
		snakey->GetEntity()->GetOldPos(oldPos);
		snakey->GetPlayer()->GetComponent<Controller>()->StopMoving();
		snakey->GetEntity()->SetPos(oldPos);
	}
}
