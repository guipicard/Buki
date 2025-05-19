#pragma once 
#include "IUpdatable.h"
#include "IFixedUpdatable.h"
#include "Observer.h"
#include "Component.h"
#include <string>
#include "Entity.h"

namespace buki
{
	struct MonoBehaviour : public Component, public IUpdatable, public IFixedUpdatable
	{
		MonoBehaviour(Entity* entity) : Component(entity) {}
		virtual ~MonoBehaviour() = default;
		virtual void Awake() = 0;
		virtual void Start() = 0;
		virtual void FixedUpdate(float dt) = 0;
		virtual void Update(float dt) = 0;
		virtual void OnCollisionEnter(Entity* other) = 0;
		virtual void OnDestroy() = 0;
	};
}
