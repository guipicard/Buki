#include "SnakeyBehaviour.h"
#include "Atlas.h"

buki::SnakeyBehaviour::SnakeyBehaviour(Entity* entity)
	: Component(entity)
{

}

void buki::SnakeyBehaviour::Update(float dt)
{
	if (m_Player == nullptr) return;
	Point2D playerpos, pos;
	m_Player->GetPosition(playerpos);
	m_Entity->GetPosition(pos);
	
	if (playerpos.x < pos.x)
	{
		m_Entity->GetComponent<Atlas>()->SetFrame("left");
	}
	else
	{
		m_Entity->GetComponent<Atlas>()->SetFrame("right");
	}
}



void buki::SnakeyBehaviour::OnNotify(const std::string& value, Entity* other)
{
}

void buki::SnakeyBehaviour::SetEgg()
{
	m_IsEgg = true;
	m_Entity->GetComponent<Atlas>()->SetFrame("egg");
}
