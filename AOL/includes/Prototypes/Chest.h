#pragma once
#include "Atlas.h"
#include "InteractObj.h"
#include "Engine.h"
#include "Entity.h"
#include "BoxCollider.h"
#include "ChestBehaviour.h"

namespace buki
{
	class Chest : public InteractObj
	{
	public:
		Chest() {}
		virtual Entity* Clone(int x, int y) override
		{
			Entity* entity = Engine::GetInstance().World().Create("chest");
			entity->SetPos(Point2D(x * 32, y * 32));
			entity->SetSize(Point2D(32, 32));

			Atlas* m_Atlas = entity->AddComponent<Atlas>();
			m_Atlas->Load("./assets/env.png");
			m_Atlas->AddFrame("closed", 64, 96, 32, 32);
			m_Atlas->AddFrame("opened", 96, 64, 32, 32);
			m_Atlas->AddFrame("empty", 96, 96, 32, 32);
			m_Atlas->SetFrame("closed");
			
			entity->AddComponent<ChestBehaviour>();
			Engine::GetInstance().Collision().AddToLayer("chest", entity);
			return entity;
		}
	};
}