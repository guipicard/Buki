#include "PlayerBehaviour.h"
#include "Point2D.h"
#include "Entity.h"
#include "Engine.h"
#include "Atlas.h"
#include "IWorld.h"
#include "Controller.h"
#include "SnakeyBehaviour.h"
#include "Animation.h"
#include "Spawner.h"
#include "BulletsBehaviour.h"
#include "HeartBehaviour.h"

buki::PlayerBehaviour::PlayerBehaviour(Entity* entity) 
	: MonoBehaviour(entity)
{
}

void buki::PlayerBehaviour::Update(float dt)
{
	if (m_Entity->GetComponent<Animation>()->IsStopped())
	{
		World().SetLoadScene(World().GetCurrentSceneName());
	}
}

void buki::PlayerBehaviour::OnNotify(const std::string& value, Entity* other)
{
	
	if (value == "chest")
	{
		if (m_HeartToCollect > 0) return;
		Point2D pos, otherPos;
		m_Entity->GetPosition(pos);
		other->GetPosition(otherPos);
		if (pos.Distance(otherPos) > 1.0f) return;
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
		m_Charges += other->GetComponent<HeartBehaviour>()->GetCharges();
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
	else if (value == "snakey")
	{
		other->OnCollisionEnter.Invoke("player", m_Entity);
	}
	else if (other == nullptr)
	{
		m_Entity->GetComponent<Controller>()->StopMoving();
	}
}

void buki::PlayerBehaviour::Shoot(std::string direction)
{
	if (m_Charges <= 0) return;
	Point2D pos;
	m_Entity->GetPosition(pos);
	Entity* bullet = m_Entity->GetComponent<Spawner>()->Spawn("playerBullet", pos.x, pos.y);
	bullet->GetComponent<BulletsBehaviour>()->SetDirection(direction);
	m_Charges--;
}
