#pragma once
#include "PhysicsService.h"
#include "Entity.h"
#include "Engine.h"
#include "box2d.h"
#include "RigidBody.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "BukiContainers.h"

buki::PhysicsService::PhysicsService()
{
	worldId = CreateWorld();
}

void buki::PhysicsService::LinearImpulse(const Entity* _entity, const Vector2 _impulse, const bool _wake)
{
	BodyId bId = _entity->GetBodyId();
	b2BodyId b2Id = { bId.index1, bId.world0, bId.revision };
	b2Body_ApplyLinearImpulse(b2Id, b2Vec2{ _impulse.x, _impulse.y }, b2Body_GetPosition(b2Id), _wake);
}

void buki::PhysicsService::SetAwake(const BodyId _id, const bool _state)
{
	b2Body_SetAwake({ _id.index1, _id.world0, _id.revision }, _state);
}

bool buki::PhysicsService::IsAwake(const BodyId _id) const
{
	return b2Body_IsAwake({ _id.index1, _id.world0, _id.revision });
}

b2BodyId buki::PhysicsService::Getb2BodyId(const BodyId _id) const
{
	return { _id.index1, _id.world0, _id.revision };
}

b2ShapeId buki::PhysicsService::Getb2ShapeId(const ShapeId _id) const
{
	return { _id.index1, _id.world0, _id.revision };
}

buki::BodyId buki::PhysicsService::CreatePhysicsBody(Entity* _entity)
{
	RigidBody* rb = _entity->GetComponent<RigidBody>();
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = (b2BodyType)rb->Type;
	bodyDef.fixedRotation = rb->FixedRotation;
	Vector2 pos = _entity->GetTransform()->GetPosition();
	bodyDef.position = { pos.x, pos.y };
	Rot rot = _entity->GetTransform()->GetRotation();
	bodyDef.rotation = { rot.c, rot.s };
	b2WorldId b2wId = b2WorldId{ worldId.index, worldId.revision };
	b2BodyId bodyId = b2CreateBody(b2wId, &bodyDef);
	return { bodyId.index1, bodyId.world0, bodyId.revision };
}

void buki::PhysicsService::DestroyPhysicsBody(BodyId _id)
{
	b2BodyId b2id = b2BodyId{ _id.index1, _id.world0, _id.revision };
	b2DestroyBody(b2id);
}

buki::WorldId buki::PhysicsService::GetPhysicsWorld() const
{
	return worldId;
}

buki::WorldId buki::PhysicsService::CreateWorld()
{
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = { 0.0f, 9.8f };
	b2WorldId wId = b2CreateWorld(&worldDef);
	worldId.index = wId.index1;
	worldId.revision = wId.revision;
	return worldId;
}

void buki::PhysicsService::SetForce(Entity* _entity, Vector2 _force, bool _wake)
{
	BodyId bId = _entity->GetBodyId();
	b2Body_ApplyForceToCenter({ bId.index1, bId.world0, bId.revision }, { _force.x, _force.y }, _wake);
}

buki::Vector2 buki::PhysicsService::GetVelocity(Entity* _entity)
{
	BodyId bId = _entity->GetBodyId();
	b2Vec2 b2Id = b2Body_GetLinearVelocity({ bId.index1, bId.world0, bId.revision });
	return { b2Id.x, b2Id.y };
}

bool buki::PhysicsService::OnCollision(Entity* _entity)
{

	return false;
}

bool buki::PhysicsService::GetContactEvents(Entity* _entity)
{
	b2WorldId wId = { worldId.index, worldId.revision };
	if (!b2World_IsValid(wId))
	{
		Engine::GetInstance().Log().LogError("invalid world");
	}
	b2BodyId b2Id = Getb2BodyId(_entity->GetBodyId());
	int capacity = b2Body_GetContactCapacity(b2Id);
	b2ContactData contactData = b2ContactData();
	contactData.manifold = b2Manifold();
	contactData.shapeIdA = b2ShapeId();
	contactData.shapeIdB = b2ShapeId();

	b2Body_GetContactData(b2Id, &contactData, capacity);
	if (contactData.shapeIdA.index1 == _entity->GetShapeId().index1 || contactData.shapeIdB.index1 == _entity->GetShapeId().index1)
	{
		return true;
	}
	return false;
	//Engine::GetInstance().Log().LogMessage(std::to_string(b2Ce.beginCount));
	//Engine::GetInstance().Log().LogMessage(std::to_string(b2Ce.endCount));
	//Engine::GetInstance().Log().LogMessage(std::to_string(sizeof(b2ContactHitEvent) / sizeof(b2Ce)));
	/*ShapeId id = { b2Id.index1, b2Id.world0, b2Id.revision };
	for (int i = 0; i < sizeof(b2ContactHitEvent) / sizeof(b2Ce); i++)
	{
		b2ShapeId b2IdA = b2Ce[i].shapeIdA;
		b2ShapeId b2IdB = b2Ce[i].shapeIdB;
		Engine::GetInstance().Log().LogMessage(std::to_string(id.index1));
		ShapeId idA = { b2IdA.index1, b2IdA.world0, b2IdA.revision };
		ShapeId idB = { b2IdB.index1, b2IdB.world0, b2IdB.revision };
		if (idA == id)
		{
			return true;
		}
		else if (idB == id)
		{
			return true;
		}
	}
	return false;*/
}

void buki::PhysicsService::Destroy()
{
	b2DestroyWorld(b2WorldId{ worldId.index, worldId.revision });
	worldId = { 0,0 };
}

void buki::PhysicsService::Reset()
{
	Destroy();
	CreateWorld();
}
