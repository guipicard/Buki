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
#include "ICollision.h"

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
			snakey->SetState("idle");
		}
	}
	Point2D pos;
	snakey->GetEntity()->GetOldPos(pos);
	if (pos.x / 2.0f != 0.0f || pos.y / 2.0f != 0.0f)
	{
		pos.x = round(pos.x / 2.0f) * 2.0f;
		pos.y = round(pos.y / 2.0f) * 2.0f;
		snakey->GetEntity()->SetPos(pos);
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
	Point2D snakeyPos, playerPos, snakeySize, playerSize, playerDirection;
	playerDirection = snakey->GetPlayer()->GetComponent<Controller>()->GetDirection();
	snakey->GetEntity()->GetPosition(snakeyPos);
	snakey->GetEntity()->GetSize(snakeySize);
	snakey->GetPlayer()->GetPosition(playerPos);
	snakey->GetPlayer()->GetSize(playerSize);
	if (playerDirection == Point2D(0.0f, 0.0f))
	{
		playerDirection = m_Velocity;
	}


	Point2D newPos, diffrence;
	diffrence = playerDirection * playerSize; // bonne distance bonne direction
	newPos = playerPos * playerDirection.Abs(); // player pos a ne pas changer est = 0
	newPos = newPos + diffrence; // player pos a changer + difference
	if (newPos.x == 0.0f) newPos.x = snakeyPos.x;
	if (newPos.y == 0.0f) newPos.y = snakeyPos.y;

	snakey->GetEntity()->SetPos(newPos);
	if (snakey->GetEntity()->GetComponent<BoxCollider>()->CheckTileCollision())
	{
		Point2D pos;
		snakey->GetEntity()->GetOldPos(pos);
		pos.x = round(pos.x / 16.0f) * 16.0f;
		pos.y = round(pos.y / 16.0f) * 16.0f;
		snakey->GetEntity()->SetPos(pos);
		snakey->GetPlayer()->GetComponent<Controller>()->StopMoving();
	}

	m_Velocity = playerDirection;
}
