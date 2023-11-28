#include "PlayerBehaviour.h"
#include "Point2D.h"
#include "Entity.h"
#include "Atlas.h"
#include "IWorld.h"
#include "Controller.h"
#include "SnakeyBehaviour.h"

buki::PlayerBehaviour::PlayerBehaviour(Entity* entity) : Component(entity)
{
}

void buki::PlayerBehaviour::Update(float dt)
{

}

void buki::PlayerBehaviour::OnNotify(const std::string& value, Entity* other)
{
	if (value == "chest")
	{
		//other->GetComponent<Atlas>()->SetFrame("opened");
		Point2D pos, otherPos;
		m_Entity->GetPosition(pos);
		other->GetPosition(otherPos);
		if (pos.Distance(otherPos) > 1.0f || m_HeartToCollect > 0) return;
		other->GetComponent<Atlas>()->SetFrame("empty");
		OnKeyPickup.Invoke("", nullptr);
		m_DoorOpened = true;
	}
	else if (value == "heart")
	{
		Point2D pos, otherPos;
		m_Entity->GetPosition(pos);
		other->GetPosition(otherPos);
		if (pos.Distance(otherPos) > 1.0f) return;
		World().Remove(other);
		m_HeartToCollect--;
		if (m_HeartToCollect == 0)
		{
			OnHeartPickup.Invoke("", nullptr);
		}
	}
	else if (value == "snakey")
	{
		if (other->GetComponent<SnakeyBehaviour>()->GetIsEgg())
		{
			// bouger l'oeuf
		}
		else
		{
			m_Entity->GetComponent<Controller>()->StopMoving();
		}
	}
	else if (value == "Door")
	{
		if (m_DoorOpened)
		{
			// fin
		}
		else
		{
			m_Entity->GetComponent<Controller>()->StopMoving();
		}
	}
	else if (other == nullptr)
	{
		m_Entity->GetComponent<Controller>()->StopMoving();
	}
}
