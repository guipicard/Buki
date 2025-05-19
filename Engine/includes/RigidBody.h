#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IFixedUpdatable.h"
#include "Vector2.h"
#include "Material.h"
#include "MassData.h"
#include "Entity.h"

namespace buki
{
	struct RigidBody : public Component, public IFixedUpdatable
	{
		enum class BodyType {
			Static = 0,

			/// zero mass, velocity set by user, moved by solver
			kinematic = 1,

			/// positive mass, velocity determined by forces, moved by solver
			dynamic = 2,

			/// number of body types
			bodyTypeCount,
		};
		BodyType Type = BodyType::dynamic;
		bool FixedRotation = false;

		RigidBody(Entity* entity) { m_Entity = entity; }
		~RigidBody() = default;
		virtual void FixedUpdate(float dt) override;
		virtual void Start() override;
		virtual void Destroy() override;

		void SetForce(Vector2 _force);
	};
}
