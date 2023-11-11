#include "CollisionService.h"
#include "Engine.h"
#include "Entity.h"
#include "Controller.h"
#include "Animation.h"

buki::CollisionService::CollisionService()
{
}

buki::CollisionService::~CollisionService()
{
	if (m_Player != nullptr)
	{
		m_Player = nullptr;
	}
}

bool buki::CollisionService::BoxColliding(std::string _name, int px, int py, int pw, int ph)
{
	auto it = m_TileMap.find(_name);
	if (it != m_TileMap.end())
	{
		// Iterate through the vector of rectangles for the given _name
		for (const RectI& rect : it->second)
		{
			// Check for collision with each rectangle
			if ((px < rect.x + rect.w &&
				px + pw > rect.x &&
				py < rect.y + rect.h &&
				py + ph > rect.y))
			{
				// Collision detected
				return true;
			}
		}
	}

	// No collision detected
	return false;
}

void buki::CollisionService::AddLayer(std::string _name, std::vector<RectI> _layer)
{
	m_TileMap.emplace(_name, _layer);
}

void buki::CollisionService::Update(float dt)
{
	if (m_Player != nullptr)
	{
		Point2D pos = m_Player->GetPos();
		Point2D size = m_Player->GetSize();
		if (m_PlayerDead)
		{
			if (m_Player->GetComponent<Animation>()->IsStopped())
			{
				buki::Engine::GetInstance()->World().Remove(m_Player);
				m_Player = nullptr;
			}
		}
		else
		{
			if (BoxColliding("Walls", pos.x, pos.y, size.x, size.y) || BoxColliding("trees", pos.x, pos.y, size.x, size.y))
			{
				m_Player->SetPos(m_Player->GetOldPos());
				buki::Engine::GetInstance()->Log().LogMessage("Collision");
			}
			else if (BoxColliding("water", pos.x, pos.y, size.x, size.y))
			{
				m_Player->GetComponent<Controller>()->LockController();
				m_Player->GetComponent<Animation>()->Play("death", false);
				m_PlayerDead = true;
				m_Player = nullptr;
			}
			else
			{
				m_Player->SetOldPos(pos);
			}
		}
	}
}

void buki::CollisionService::Draw()
{
}

void buki::CollisionService::AddPlayer(Entity* _player)
{
	m_Player = _player;
	m_PlayerDead = false;
}
