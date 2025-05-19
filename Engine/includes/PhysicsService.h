#pragma once
#include "IPhysics.h"
#include "stdint.h"
//#include "box2d.h"

namespace buki
{
	struct WorldId
	{
		uint16_t index;
		uint16_t revision;
	};
	struct BodyId
	{
		int32_t index1;
		uint16_t world0;
		uint16_t revision;
	};
	struct ShapeId
	{
		int32_t index1;
		uint16_t world0;
		uint16_t revision;
		bool operator==(ShapeId o) { return index1 == o.index1 && world0 == o.world0 && revision == o.revision; }
	};

	//struct GetContactEvents : b2ContactEvents
	//{

	//};

	struct PhysicsService : public IPhysics
	{
		PhysicsService();
		virtual void LinearImpulse(const Entity* _entity, const Vector2 _impulse, const bool _wake) override;
		virtual void SetAwake(const BodyId _id, const bool _state) override;
		virtual bool IsAwake(const BodyId _id) const override;
		virtual b2BodyId Getb2BodyId(const BodyId _id) const override;
		virtual b2ShapeId Getb2ShapeId(const ShapeId _id) const override;
		virtual WorldId GetPhysicsWorld() const override;
		virtual BodyId CreatePhysicsBody(Entity* _entity) override;
		virtual void DestroyPhysicsBody(BodyId _id) override;
		virtual WorldId CreateWorld() override;
		virtual void SetForce(Entity* _entity, Vector2 _force, bool _wake) override;
		virtual Vector2 GetVelocity(Entity* _entity) override;
		virtual bool OnCollision(Entity* _entity) override;
		virtual bool GetContactEvents(Entity* _entity) override;
		virtual void Destroy() override;
		virtual void Reset() override;
	private:
		WorldId worldId;
	};
}