#pragma once
#include "Circle.h"
#include "box2d.h"
#include "Entity.h"
#include "RigidBody.h"
#include "IGraphics.h"
#include "ILogger.h"

void buki::Circle::Draw(float alpha)
{
	if (DrawShape)
	{
		Vector2 pos = m_Entity->GetTransform()->GetPosition();
		float angle = m_Entity->GetTransform()->GetRotation().GetRadians();
		Graphics().FillCircle(pos.x, pos.y, Collider.Radius, angle, ShapeColor);
	}
	if (DebugDraw)
	{
		Vector2 pos = m_Entity->GetTransform()->GetPosition();
		float angle = m_Entity->GetTransform()->GetRotation().GetRadians();
		Graphics().DrawCircle(pos.x, pos.y, Collider.Radius, angle, DebugColor);
	}
}

void buki::Circle::Start()
{
}

void buki::Circle::Destroy()
{
}

void buki::Circle::SetPhysics()
{
	if (!m_Entity->GetComponent<RigidBody>())
	{
		m_Entity->AddComponent<RigidBody>();
		m_Entity->ActivatePhysics();
	}
	else if (!m_Entity->HasPhysics())
	{
		m_Entity->ActivatePhysics();
	}
	b2ShapeDef def = b2DefaultShapeDef();
	def.density = Collider.Density;
	def.friction = Collider.Friction;
	def.restitution = Collider.Restitution;
	BodyId bId = m_Entity->GetBodyId();
	b2BodyId b2Id = b2BodyId{ bId.index1, bId.world0, bId.revision };
	b2Circle circle;
	circle.center = { Collider.PositionOffset.x, Collider.PositionOffset.y };
	circle.radius = Collider.Radius;
	b2ShapeId sId = b2CreateCircleShape(b2Id, &def, &circle);
	m_Entity->SetShapeId({ sId.index1, sId.world0, sId.revision });
}
