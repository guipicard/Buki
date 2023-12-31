#pragma once
#include "Character.h"
#include "Engine.h"
#include "ICollision.h"
#include "Atlas.h"
#include "SnakeyBehaviour.h"
#include "Entity.h"
#include "BoxCollider.h"

namespace buki
{
	class Snakey : public Character
	{
	public:
		Snakey(int speed) : Character(speed)
		{

		}
		virtual Entity* Clone(int x, int y) override
		{
			Entity* entity = Engine::GetInstance().World().Create("snakey");
			entity->SetPos(Point2D(x * 32, y * 32));
			entity->SetSize(Point2D(32, 32));

			Atlas* atlas = entity->AddComponent<Atlas>();
			atlas->Load("./assets/monsters.png");
			atlas->AddFrame("left", 1, 1, 32, 32);
			atlas->AddFrame("left-center", 34, 0, 32, 32);
			atlas->AddFrame("center-left", 2 * 32 + 3, 0, 32, 32);
			atlas->AddFrame("center-right", 3 * 32 + 4, 0, 32, 32);
			atlas->AddFrame("right-center", 4 * 32 + 5, 0, 32, 32);
			atlas->AddFrame("right", 5 * 32 + 6, 0, 32, 32);
			atlas->AddFrame("egg", 1, 9 * 32 + 10, 32, 32);
			atlas->AddFrame("cracked", 34, 9 * 32 + 10, 32, 32);
			atlas->SetFrame("left");

			SnakeyBehaviour* snakeyBehaviour = entity->AddComponent<SnakeyBehaviour>();
			BoxCollider* collider = entity->AddComponent<BoxCollider>();
			collider->AddIncludeLayer("playerBullets");

			entity->OnCollisionEnter.AddListener(snakeyBehaviour);
			Engine::GetInstance().Collision().AddToLayer("snakey", entity);
			return entity;
		}
	};

}
