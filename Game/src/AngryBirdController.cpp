#pragma once
#include "AngryBirdController.h"
#include "Engine.h"
#include "RigidBody.h"
#include "Circle.h"
#include "Prefabs.h"
#include "Spawner.h"

buki::AngryBirdController::AngryBirdController(Entity* _entity)
	: MonoBehaviour(_entity)
{
	Awake();
}

void buki::AngryBirdController::Awake()
{
	spawner = m_Entity->AddComponent<Spawner>();
	spawner->AddPrototype("bird", new Bird());
	anchor = World().Find("anchor");
	anchorPos = anchor->GetTransform()->GetPosition();
	bird = spawner->Spawn("bird", anchorPos, Vector2(1.0f, 1.0f), 0.0f);
	clickPos = Vector2::ZERO;
	forceMultiplier = 4.0f;
	shotLength = 4.0f;
}

void buki::AngryBirdController::Start()
{
}

void buki::AngryBirdController::FixedUpdate(const float dt)
{
}

void buki::AngryBirdController::Update(const float dt)
{
	float x, y;
	Input().GetMousePosition(&x, &y);
	Vector2 mousePos = Vector2(x, y);
	Vector2 birdPos = bird->GetTransform()->GetPosition();
	float birdRadius = bird->GetTransform()->GetSize().x;
	if (Input().IsButtonDown(0))
	{
		if (!thrown)
		{
			aiming = true;
			thrown = true;
			clickPos = mousePos;
		}
		else
		{
			Reset();
			thrown = false;
		}
	}
	if (aiming)
	{
		if (Input().IsButtonUp(0))
		{
			if (aiming)
			{
				aiming = false;
				clickPos = Vector2::ZERO;
				Throw(anchorPos - bird->GetTransform()->GetPosition());
			}
		}
		else
		{
			Vector2 offset = clickPos - mousePos;
			if (offset.Lenth() > shotLength) offset = offset.GetNormalized() * shotLength;
			Vector2 slignPos = anchorPos - offset;
			bird->GetTransform()->SetPosition(slignPos);
		}
	}
}

void buki::AngryBirdController::OnCollisionEnter(Entity* other)
{
}

void buki::AngryBirdController::OnDestroy()
{
}

void buki::AngryBirdController::Throw(const Vector2 _v)
{
	bird->ActivatePhysics();
	Physics().LinearImpulse(bird, _v * forceMultiplier, true);
}

void buki::AngryBirdController::Reset()
{
	bird->DeactivatePhysics();
	bird->GetTransform()->SetPosition(anchorPos);
	bird->GetTransform()->SetRotation(0.0f);
}
