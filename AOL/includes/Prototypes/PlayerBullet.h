#pragma once
#include "Entity.h"
#include "Engine.h"
#include "Bullet.h"
#include "Atlas.h"
#include "BulletsBehaviour.h"

namespace buki
{
	class PlayerBullet : public Bullet
	{
	public:
		PlayerBullet(int speed, float distance) : Bullet(speed, distance) {}
		virtual Entity* Clone(int x, int y) override
		{
			Entity* entity = Engine::GetInstance().World().Create("bullet");
			Point2D pos = Point2D(x, y);
			entity->SetPos(pos);
			entity->SetSize(Point2D(32, 32));

			BulletsBehaviour* bulletBehaviour = entity->AddComponent<BulletsBehaviour>();
			bulletBehaviour->SetSpeed(m_Speed);
			bulletBehaviour->SetDistance(m_Distance);
			bulletBehaviour->SetPos(pos);

			Atlas* atlas = entity->AddComponent<Atlas>();
			atlas->Load("./assets/others.png");
			atlas->AddFrame("down", 0, 96, 32, 32);
			atlas->AddFrame("left", 32, 96, 32, 32);
			atlas->AddFrame("up", 64, 96, 32, 32);
			atlas->AddFrame("right", 96, 96, 32, 32);
			atlas->SetFrame("down");

			Engine::GetInstance().Collision().AddToLayer("playerBullets", entity);

			return entity;
		}
	};
}