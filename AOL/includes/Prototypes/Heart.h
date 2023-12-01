#pragma once
#include "Atlas.h"
#include "InteractObj.h"
#include "Engine.h"
#include "Entity.h"
#include "BoxCollider.h"
#include "ChestBehaviour.h"
#include "HeartBehaviour.h"

namespace buki
{
	class Heart : public InteractObj
	{
	public:
		Heart() {}
		virtual Entity* Clone(int x, int y) override
		{
			Entity* entity = Engine::GetInstance().World().Create("heart");
			entity->SetPos(Point2D(x * 32, y * 32));
			entity->SetSize(Point2D(32, 32));

			Atlas* m_Atlas = entity->AddComponent<Atlas>();
			m_Atlas->Load("./assets/env.png");
			m_Atlas->AddFrame("active", 32, 96, 32, 32);
			m_Atlas->SetFrame("active");

			entity->AddComponent<HeartBehaviour>();

			Engine::GetInstance().Collision().AddToLayer("heart", entity);
			return entity;
		}
	};
}