#pragma once 
#include "Character.h"
#include "Engine.h"
#include "Entity.h"
#include "Animation.h"
#include "Controller.h"


class Lolo : public Character
{
public:
	Lolo(int speed, int x, int y) : Character(speed, x, y)
	{
		
	}
	virtual Character* Clone() override
	{
		auto _inst = new Lolo(m_Speed, m_X, m_Y);
		Entity* entity = Engine::GetInstance().World().Create("Lolo");
		entity->SetPos(Point2D(m_X, m_Y));
		entity->SetSize(Point2D(32, 32));
		Animation* anim = entity->AddComponent<Animation>();
		anim->Load("./assets/lolo.png");
		// move anims
		anim->Init(7, 32, 32);
		anim->AddClip("move_down", 0, 5, 0.2f);
		anim->AddClip("move_left", 7, 5, 0.2f);
		anim->AddClip("move_up", 14, 5, 0.2f);
		anim->AddClip("move_right", 21, 5, 0.2f);
		// idle anims
		anim->AddClip("idle_down", 5, 2, 0.2f);
		anim->AddClip("idle_left", 12, 2, 0.2f);
		anim->AddClip("idle_up", 19, 2, 0.2f);
		anim->AddClip("idle_right", 26, 2, 0.2f);
		//death clip
		anim->AddClip("death", 28, 4, 0.4f);
		anim->Play("idle_down", true);
		Controller* controller = entity->AddComponent<Controller>();
		controller->SetSpeed(50.0f);
		return _inst;
	}
};