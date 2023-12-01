#include "SnakeyIdle.h"
#include "Atlas.h"
#include "Entity.h"
#include "Engine.h"
#include "SnakeyBehaviour.h"
#include "Controller.h"
#include "Animation.h"

buki::SnakeyIdle::SnakeyIdle()
{
}

void buki::SnakeyIdle::Start(SnakeyBehaviour* snakey)
{
}

void buki::SnakeyIdle::Update(float dt, SnakeyBehaviour* snakey)
{
	Point2D playerpos, pos;
	snakey->GetPlayer()->GetPosition(playerpos);
	snakey->GetEntity()->GetPosition(pos);

	if (playerpos.x < pos.x)
	{
		snakey->GetEntity()->GetComponent<Atlas>()->SetFrame("left");
	}
	else
	{
		snakey->GetEntity()->GetComponent<Atlas>()->SetFrame("right");
	}
}

void buki::SnakeyIdle::Exit(SnakeyBehaviour* snakey)
{
}

void buki::SnakeyIdle::OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey)
{
	if (other == nullptr) return;
	if (value == "player")
	{
		other->GetComponent<Controller>()->StopMoving();
	}
	else if (value == "playerBullets")
	{
		Engine::GetInstance().World().Remove(other);
		snakey->SetState("egg");
	}
}
