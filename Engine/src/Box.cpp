#pragma once
#include "Box.h"
#include "box2d.h"
#include "Entity.h"
#include "RigidBody.h"
#include "IGraphics.h"
#include "ILogger.h"

void buki::Box::Draw(float alpha)
{
	if (DrawShape)
	{
		Vector2 pos = m_Entity->GetTransform()->GetPosition();
		float angle = m_Entity->GetTransform()->GetRotation().GetRadians();
		Graphics().FillRect(pos.x, pos.y, Collider.Size.x, Collider.Size.y, angle, ShapeColor);
	}
	if (DebugDraw)
	{
		Vector2 pos = m_Entity->GetTransform()->GetPosition();
		float angle = m_Entity->GetTransform()->GetRotation().GetRadians();
		Graphics().DrawRect(pos.x, pos.y, Collider.Size.x, Collider.Size.y, angle, DebugColor);
	}
}

void buki::Box::Start()
{
}

void buki::Box::Destroy()
{
}

void buki::Box::SetPhysics()
{
	if (!m_Entity->GetComponent<RigidBody>())
	{
		return;
	}
	b2ShapeDef def = b2DefaultShapeDef();
	def.density = Collider.Density;
	def.friction = Collider.Friction;
	def.restitution = Collider.Restitution;
	Vector2 size = Collider.Size;
	BodyId bId = m_Entity->GetBodyId();
	b2BodyId b2Id = b2BodyId{ bId.index1, bId.world0, bId.revision };
	b2Polygon box = b2MakeBox(size.x, size.y);
	b2ShapeId sId = b2CreatePolygonShape(b2Id, &def, &box);
	b2Body_GetUserData(b2Id);
	m_Entity->SetShapeId({ sId.index1, sId.world0, sId.revision });
}
