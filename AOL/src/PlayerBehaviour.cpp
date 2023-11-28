#include "PlayerBehaviour.h"
#include "Point2D.h"
#include "Entity.h"
#include "Atlas.h"
#include "IWorld.h"

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
		m_Entity->GetPosition(&pos);
		other->GetPosition(&otherPos);
		if (pos.Distance(otherPos) > 1.0f || m_HeartToCollect > 0) return;
		other->GetComponent<Atlas>()->SetFrame("empty");
		OnKeyPickup.Invoke("", nullptr);
		//m_Entity->GetComponent<PlayerBehaviour>()->OnKeyPickup.RemoveListener(this);
	}
	else if (value == "heart")
	{
		Point2D pos, otherPos;
		m_Entity->GetPosition(&pos);
		other->GetPosition(&otherPos);
		if (pos.Distance(otherPos) > 1.0f) return;
		World().Remove(other);
		m_HeartToCollect--;
		if (m_HeartToCollect == 0)
		{
			OnHeartPickup.Invoke("", nullptr);
		}
	}
	
}
