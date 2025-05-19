#pragma once

struct b2BodyId;
struct b2ShapeId;
namespace buki
{
	struct WorldId;
	struct BodyId;
	struct ShapeId;
	struct Vector2;
	struct Entity;

	struct IPhysics
	{
		virtual ~IPhysics() = default;

		virtual void LinearImpulse(const Entity* _entity, const Vector2 _impulse, const bool _wake) = 0;
		virtual void SetAwake(const BodyId _id, const bool _state) = 0;
		virtual bool IsAwake(const BodyId _id) const = 0;

		virtual b2BodyId Getb2BodyId(const BodyId _id) const = 0;

		virtual b2ShapeId Getb2ShapeId(const ShapeId _id) const = 0;

		virtual WorldId GetPhysicsWorld() const = 0;

		virtual BodyId CreatePhysicsBody(Entity* _entity) = 0; // Create the physics body in Box2d World

		virtual void DestroyPhysicsBody(BodyId _id) = 0; // Create the physics body in Box2d World

		virtual WorldId CreateWorld() = 0;

		virtual void SetForce(Entity* _entity, Vector2 _force, bool _wake) = 0;

		virtual Vector2 GetVelocity(Entity* _entity) = 0;

		virtual bool OnCollision(Entity* _entity) = 0;

		virtual bool GetContactEvents(Entity* _entity) = 0;

		virtual void Destroy() = 0;

		virtual void Reset() = 0;


	};
}
