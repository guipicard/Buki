#include "SnakeyBehaviour.h"
#include "Atlas.h"
#include "SnakeyIdle.h"
#include "SnakeyEgg.h"
#include "SnakeyFlying.h"
#include "SnakeyOut.h"
#include "Engine.h"
#include "Animation.h"

buki::SnakeyBehaviour::SnakeyBehaviour(Entity* entity)
	: Component(entity)
{
	m_Entity->GetPosition(m_StartPos);
	m_States.emplace("idle", new SnakeyIdle());
	m_States.emplace("egg", new SnakeyEgg());
	m_States.emplace("flying", new SnakeyFlying());
	m_States.emplace("out", new SnakeyOut());
	SetState("idle");
}

buki::SnakeyBehaviour::~SnakeyBehaviour()
{
	for (auto state : m_States)
	{
		delete state.second;
	}
	m_States.clear();
}

void buki::SnakeyBehaviour::SetState(const std::string& state)
{
	if (m_States.count(state) > 0)
	{
		if (m_CurrentState != nullptr)
		{
			m_CurrentState->Exit(this);
		}
		m_CurrentState = m_States[state];
		m_CurrentState->Start(this);
	}
}

void buki::SnakeyBehaviour::Update(float dt)
{
	if (m_Player == nullptr) return;
	m_CurrentState->Update(dt, this);
}

void buki::SnakeyBehaviour::OnNotify(const std::string& value, Entity* other)
{
	m_CurrentState->OnCollisionEnter(value, other, this);
}

void buki::SnakeyBehaviour::ReSpawn()
{
	m_Entity->SetPos(m_StartPos);
	
	SetState("idle");
}
