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
		if (other == nullptr) return;
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
		if (other == nullptr) return;
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
		HeartBehaviour* hb = other->GetComponent<HeartBehaviour>();
		if (hb != nullptr)
		{
			int charges = hb->GetCharges();
			m_Charges += charges;
		}
	}
	else if (value == "door")
	{
		if (other == nullptr) return;
		if (m_DoorOpened)
		{
			m_Entity->GetComponent<Controller>()->LockController(true);
			Point2D pos, otherPos;
			m_Entity->GetPosition(pos);
			other->GetPosition(otherPos);
			float distance = pos.Distance(otherPos);
			if (distance < 6.0f)
			{
				World().LoadNextScene();
			}
		}
		else
		{
			m_Entity->GetComponent<Controller>()->StopMoving();
		}
	}
	else if (value == "snakey")
	{
		if (other == nullptr) return;
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
	Entity* bullet = m_Entity->GetComponent<Spawner>()->Spawn("playerBullet", static_cast<int>(pos.x), static_cast<int>(pos.y));
	bullet->GetComponent<BulletsBehaviour>()->SetDirection(direction);
	m_Charges--;
}
