#pragma once 
#include "Character.h"
#include "Engine.h"
#include "Entity.h"
#include "Animation.h"
#include "Controller.h"
#include "BoxCollider.h"
#include "PlayerBehaviour.h"
#include "PlayerBullet.h"


class Lolo : public Character
{
public:
	Lolo(int speed) : Character(speed)
	{
		
	}
	virtual Entity* Clone(int x, int y) override
	{
		Entity* entity = Engine::GetInstance().World().Create("Lolo");
		entity->SetPos(Point2D(x * 32, y * 32));
		entity->SetSize(Point2D(32, 32));
		Animation* anim = entity->AddComponent<Animation>();
		anim->Load("./assets/lolo.png");
		// move anims
		anim->Init(0, 32, 32);
		anim->AddClip("move_down", 0, 0, 5, 0.05f);
		anim->AddClip("move_left", 0, 1, 5, 0.05f);
		anim->AddClip("move_up", 0, 2, 5, 0.05f);
		anim->AddClip("move_right", 0, 3, 5, 0.05f);
		// idle anims
		anim->Init(5, 32, 32);
		anim->AddClip("idle_down", 5, 0, 2, 0.4f);
		anim->AddClip("idle_left", 5, 1, 2, 0.4f);
		anim->AddClip("idle_up", 5, 2, 2, 0.4f);
		anim->AddClip("idle_right", 5, 3, 2, 0.4f);
		//death clip
		anim->AddClip("death", 0, 4, 4, 0.4f);
		anim->Play("idle_down", true);
		Controller* controller = entity->AddComponent<Controller>();
		controller->SetSpeed(m_Speed);
		BoxCollider* boxCollier = entity->AddComponent<BoxCollider>();
		boxCollier->AddIncludeLayer("chest");
		boxCollier->AddIncludeLayer("heart");
		boxCollier->AddIncludeLayer("door");

		Spawner* spawner = entity->AddComponent<Spawner>();
		PlayerBullet* bulletProto = new PlayerBullet(500, 512.0f);
		spawner->AddPrototype("playerBullet", bulletProto);
		PlayerBehaviour* playerBehaviour = entity->AddComponent<PlayerBehaviour>();
		entity->OnCollisionEnter.AddListener(playerBehaviour);

		Engine::GetInstance().Collision().AddToLayer("player", entity);
		return entity;
	}
};
