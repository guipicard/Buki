#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	struct Spawner;
	struct AngryBirdController : public MonoBehaviour
	{
		AngryBirdController(Entity* _entity);
		~AngryBirdController() = default;

		virtual void Awake() override;
		virtual void Start() override;
		virtual void FixedUpdate(const float dt) override;
		virtual void Update(const float dt) override;
		virtual void OnCollisionEnter(Entity* other) override;
		virtual void OnDestroy() override;
	private:
		Entity* bird = nullptr;
		Entity* anchor = nullptr;
		Spawner* spawner;
		Vector2 anchorPos;
		Vector2 clickPos;
		void Throw(const Vector2 _v);
		void Reset();
		bool aiming = false;
		bool thrown = false;
		float forceMultiplier;
		float shotLength;
	};
}