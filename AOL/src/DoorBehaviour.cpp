#include "DoorBehaviour.h"
#include "Atlas.h"

buki::DoorBehaviour::DoorBehaviour(Entity* entity)
	: Component(entity)
{
}

void buki::DoorBehaviour::Update(float dt)
{
}

void buki::DoorBehaviour::OnNotify(const std::string& value, Entity* other)
{
	m_Entity->GetComponent<Atlas>()->SetFrame("opened");
}
