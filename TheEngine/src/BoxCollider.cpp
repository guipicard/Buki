#pragma once
#include "BoxCollider.h"
#include "Component.h"
#include "Engine.h"
#include "Tilemap.h"
#include "RectF.h"

buki::BoxCollider::BoxCollider(Entity* entity) : Component(entity)
{
	m_Offset = Point2D(1.0f, 1.0f);
	m_Entity->GetSize(m_Size);
	m_Size = m_Size - m_Offset;
}

void buki::BoxCollider::Update(float dt)
{
	if (m_Tilemap != nullptr)
	{
		CheckTileCollision();
	}
	CheckCollision();
}

void buki::BoxCollider::Draw()
{
	if (canDraw)
	{
		Point2D pos;

		m_Entity->GetPosition(pos);
		RectF myRect(pos.x, pos.y, m_Size.x, m_Size.y);
		Graphics().DrawRect(myRect, Color::GREEN);
	}
}

bool buki::BoxCollider::CheckTileCollision()
{
	int tileNum;
	Point2D pos;

	m_Entity->GetPosition(pos);
	for (auto layer : m_TileIncludeLayers)
	{
		if (m_Tilemap->IsBoxColliding(layer, pos.x, pos.y, m_Size.x - 1, m_Size.y - 1, &tileNum))
		{
			m_Entity->OnCollisionEnter.Invoke(layer, nullptr);
			return true;
		}
	}
	return false;
}

void buki::BoxCollider::CheckCollision()
{
	Entity* other;
	for (auto layer : m_IncludeLayers)
	{
		if (Collision().CollideWithLayer(m_Entity, layer, &other))
		{
			m_Entity->OnCollisionEnter.Invoke(layer, other);
		}
	}
}
