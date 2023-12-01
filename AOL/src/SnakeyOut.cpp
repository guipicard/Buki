#include "SnakeyOut.h"
#include "SnakeyBehaviour.h"

buki::SnakeyOut::SnakeyOut()
{
	m_Timer = 10.0f;
	m_Elapsed = 0.0f;
}

void buki::SnakeyOut::Start(SnakeyBehaviour* snakey)
{
	m_Timer = 10.0f;
	m_Elapsed = 0.0f;
}

void buki::SnakeyOut::Update(float dt, SnakeyBehaviour* snakey)
{
	m_Elapsed += dt;
	if (m_Elapsed > m_Timer)
	{
		snakey->ReSpawn();
	}
}

void buki::SnakeyOut::Exit(SnakeyBehaviour* snakey)
{
}

void buki::SnakeyOut::OnCollisionEnter(std::string value, Entity* other, SnakeyBehaviour* snakey)
{
}
