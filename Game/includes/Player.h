#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	struct Sprite; 
	struct RigidBody;
	struct Animation;
	struct Box;
	struct Player : public MonoBehaviour
	{
		Player(Entity* entity);
		~Player() = default;
		virtual void Awake() override;
		virtual void Start() override;
		virtual void FixedUpdate(const float dt) override;
		virtual void Update(const float dt) override;
		virtual void OnCollisionEnter(Entity* other) override;
		virtual void OnDestroy() override;
		float GetSpeed() const { return m_Speed; }
		void SetSpeed(float speed) { m_Speed = speed; }
	private:
		Animation* playerAnim;
		Box* m_Collider;
		RigidBody* m_Rigidbody;
		float m_Speed;
		float m_JumpForce;
		float maxVel;
		bool jump;
		void Jump();
		void Move(Vector2 _dir);
		//Vector2 direction;
	};
}
