#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	struct Spawner;
	struct Sprite;
	struct Collider;
	struct RigidBody;
	struct ShapesController : public MonoBehaviour
	{
		ShapesController(Entity* entity);
		~ShapesController() = default;
		virtual void Awake() override;
		virtual void Start() override;
		virtual void FixedUpdate(const float dt) override;
		virtual void Update(const float dt) override;
		virtual void OnCollisionEnter(Entity* other) override;
		virtual void OnDestroy() override;
	private:
		Spawner* spawner;
	};
}
