#include "ChestBehaviour.h"
#include "Entity.h"
#include "Atlas.h"

buki::ChestBehaviour::ChestBehaviour(Entity* entity)
	: MonoBehaviour(entity)
{

}

void buki::ChestBehaviour::Update(float dt)
{
}

void buki::ChestBehaviour::OnNotify(const std::string& value, Entity* other)
{
	m_Entity->GetComponent<Atlas>()->SetFrame("opened");
}
