#pragma once
#include "CircleCollider.h"
#include "Component.h"
#include "Engine.h"
#include "Tilemap.h"
#include "Point2D.h"
#include "RectF.h"

buki::CircleCollider::CircleCollider(Entity* entity) : Component(entity)
{
}

void buki::CircleCollider::Update(float dt)
{
	if (m_Tilemap != nullptr)
	{
		CheckCollision();
	}
}

void buki::CircleCollider::Draw()
{
	if (canDraw)
	{
		Point2D pos;
		Point2D size;
		m_Entity->GetPosition(pos);
		m_Entity->GetSize(size);
		float x = pos.x + (size.x / 2);
		float y = pos.y + (size.y / 2);
		float r = size.x / 2;
		Graphics().DrawCircle(x, y, r, Color::GREEN);
	}
}

void buki::CircleCollider::CheckCollision()
{
	int tileNum;
	Point2D pos;
	Point2D size;
	m_Entity->GetPosition(pos);
	m_Entity->GetSize(size);
	for (auto layer : m_TileIncludeLayers)
	{
		/*if (m_Tilemap->IsColliding(layer, pos.x, pos.y, size.x, size.y, &tileNum))
		{
			SetOldPos();
			break;
		}*/
	}
}

void buki::CircleCollider::SetOldPos()
{
	Point2D _oldPos = Point2D();
	m_Entity->GetOldPos(_oldPos);
	m_Entity->SetPos(_oldPos);
}