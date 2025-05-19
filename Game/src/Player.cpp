#pragma once
#include "Player.h"
#include "Animation.h"
#include "Engine.h"
#include "Ekey.h"
#include "RigidBody.h"
#include "Box.h"
#include "Entity.h"
#include "Camera.h"

buki::Player::Player(Entity* entity) : MonoBehaviour(entity)
{
	maxVel = 4.0f;
	jump = false;

	m_Rigidbody = m_Entity->AddComponent<RigidBody>();
	m_Rigidbody->FixedRotation = true;
	m_Collider = m_Entity->AddComponent<Box>();
	m_Collider->DebugDraw = true;
	m_Collider->Collider.Restitution = 0.0f;
	m_Collider->Collider.Friction = 0.9f;
	m_Collider->Collider.Size = { 1.0, 1.4f };
	m_Entity->ActivatePhysics();

	m_JumpForce = 40.0f;
	m_Speed = 100.0f;

	playerAnim = m_Entity->AddComponent<Animation>();
	playerAnim->Load("./assets/mossy cavern/BlueWizard Animations/BlueWizard/BlueWizardSpritesheet.png");
	playerAnim->Init(0, 512, 512);
	playerAnim->AddClip("Idle", 0, 0, 20, 0.05f);

	//playerAnim->Load("./assets/mossy cavern/BlueWizard Animations/BlueWizard/BlueWizardSpritesheet.png");
	//playerAnim->Init(0, 512, 512);
	playerAnim->AddClip("Walk", 0, 1, 20, 0.05f);

	//playerAnim->Load("./assets/mossy cavern/BlueWizard Animations/BlueWizard/BlueWizardSpritesheet.png");
	//playerAnim->Init(0, 512, 512);
	playerAnim->AddClip("JumpUp", 0, 2, 4, 0.2f);
	playerAnim->AddClip("JumpDown", 3, 2, 4, 0.2f);

	//playerAnim->Load("./assets/mossy cavern/BlueWizard Animations/BlueWizard/BlueWizardSpritesheet.png");
	//playerAnim->Init(0, 512, 512);
	playerAnim->AddClip("Dash", 0, 2, 16, 0.01f);
}

void buki::Player::Awake()
{
}

void buki::Player::Start()
{
}

void buki::Player::FixedUpdate(const float dt)
{
	
}

void buki::Player::Update(const float dt)
{
	Vector2 vel = Physics().GetVelocity(m_Entity);
	if (jump)
	{
		if (Physics().GetContactEvents(m_Entity) && vel.y > 0.0f)
		{
			jump = false;
			Log().LogMessage("hit");
		}
	}
	//if (!jump || playerAnim->IsStopped())
	if (vel.y > 0)
	if (!jump)
	{
		if (abs(vel.x) > 0.0f)
		{
			playerAnim->Play("Walk", true);
		}
		else
		{
			playerAnim->Play("Idle", true);
		}
	}
	if (Input().IsKeyDown(EKey::EKEY_SPACE) && !jump)
	{
		Jump();
	}
	if (Input().IsKeyPressed(EKey::EKEY_A))
	{
		Move({ -1, 0 });
	}
	if (Input().IsKeyPressed(EKey::EKEY_D))
	{
		Move({ 1, 0 });
	}
	if (Input().IsKeyPressed(EKey::EKEY_LEFTSHIFT))
	{

	}
	if (Input().IsKeyPressed(EKey::EKEY_P))
	{
		World().SetLoadScene("Menu");
	}
	Vector2 camPos, newCampos;
	camPos = Graphics().GetCamera()->position;
	newCampos = Graphics().GetCamera()->position;
	newCampos.x = m_Entity->GetTransform()->GetPosition().x;
	//Graphics().SetCameraPosition(newCampos + ((newCampos - camPos) * dt));
	Graphics().SetCameraPosition(newCampos);
}

void buki::Player::OnCollisionEnter(Entity* other)
{

}

void buki::Player::OnDestroy()
{
}

void buki::Player::Jump()
{
	Physics().LinearImpulse(m_Entity, Vector2(0, -1) * m_JumpForce, true);
	playerAnim->Play("JumpUp", false);
	//jump = true;
}

void buki::Player::Move(Vector2 _dir)
{
	if (_dir.x < 0)
	{
		playerAnim->SetFlip(true, false);
	}
	else if (_dir.x > 0)
	{
		playerAnim->SetFlip(false, false);
	}
	float velX = Physics().GetVelocity(m_Entity).x;
	if (abs(velX) < maxVel)
	{
		Physics().SetForce(m_Entity, _dir * m_Speed, true);
	}
}
