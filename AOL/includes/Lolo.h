#pragma once 
#include "Character.h"
#include "Engine.h"
#include "Entity.h"
#include "Animation.h"
#include "Controller.h"
#include "BoxCollider.h"
#include "PlayerBehaviour.h"


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
		anim->Init(7, 32, 32);
		anim->AddClip("move_down", 0, 5, 0.05f);
		anim->AddClip("move_left", 7, 5, 0.05f);
		anim->AddClip("move_up", 14, 5, 0.05f);
		anim->AddClip("move_right", 21, 5, 0.05f);
		// idle anims
		anim->AddClip("idle_down", 5, 2, 0.4f);
		anim->AddClip("idle_left", 12, 2, 0.4f);
		anim->AddClip("idle_up", 19, 2, 0.4f);
		anim->AddClip("idle_right", 26, 2, 0.4f);
		//death clip
		anim->AddClip("death", 28, 4, 0.4f);
		anim->Play("idle_down", true);
		Controller* controller = entity->AddComponent<Controller>();
		controller->SetSpeed(m_Speed);
		BoxCollider* boxCollier = entity->AddComponent<BoxCollider>();
		boxCollier->AddIncludeLayer("chest");
		boxCollier->AddIncludeLayer("heart");
		boxCollier->AddIncludeLayer("door");
		PlayerBehaviour* playerBehaviour = entity->AddComponent<PlayerBehaviour>();
		entity->OnCollisionEnter.AddListener(playerBehaviour);
		//Engine::GetInstance().Collision().AddToLayer("player", entity);
		return entity;
	}
};