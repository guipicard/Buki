#pragma once
#include "ShapesController.h"
#include "Engine.h"
#include "Prefabs.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "BoxCollider.h"
#include "RigidBody.h"
#include "Spawner.h"
#include "Text.h"

buki::ShapesController::ShapesController(Entity* entity)
	: MonoBehaviour(entity)
{
	Awake();
}

void buki::ShapesController::Awake()
{
	spawner = m_Entity->AddComponent<Spawner>();
	spawner->AddPrototype("circle", new CircleShape());
	spawner->AddPrototype("rectangle", new RectangleShape());
	Start();
}

void buki::ShapesController::Start()
{
	
}

void buki::ShapesController::FixedUpdate(const float dt)
{
}

void buki::ShapesController::Update(const float dt)
{
	if (Input().IsKeyDown(EKey::EKEY_BACKSPACE))
	{
		World().SetLoadScene("Menu");
	}
	float mouseX, mouseY;
	Input().GetMousePosition(&mouseX, &mouseY);
	Vector2 pos = Vector2(mouseX, mouseY);
	Vector2 size = Vector2();
	if (Input().IsButtonDown(0))
	{
		spawner->Spawn("rectangle", pos, size, 0.0f);
	}
	if (Input().IsButtonDown(2))
	{
		spawner->Spawn("circle", pos, size, 0.0f);
	} 

	for (auto e : World().GetEntitiesInWorld())
	{
		if (e == nullptr) return;
		Transform* tm = e->GetTransform();
		Vector2 pos = tm->GetPosition();
		if (pos.y > 30.0f)
		{
			World().Remove(e);
		}
	}
}

void buki::ShapesController::OnCollisionEnter(Entity* other)
{
}

void buki::ShapesController::OnDestroy()
{
}


