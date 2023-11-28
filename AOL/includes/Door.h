#pragma once
#include "Atlas.h"
#include "InteractObj.h"
#include "Engine.h"
#include "Entity.h"
#include "DoorBehaviour.h"

namespace buki
{
	class Door : public InteractObj
	{
	public:
		Door() {}
		virtual Entity* Clone(int x, int y) override
		{
			Entity* entity = Engine::GetInstance().World().Create("door");
			entity->SetPos(Point2D(x * 32, y * 32) - Point2D(1.0f, 1.0f));
			entity->SetSize(Point2D(32, 32));

			Atlas* m_Atlas = entity->AddComponent<Atlas>();
			m_Atlas->Load("./assets/env.png");
			m_Atlas->AddFrame("closed", 20 * 32, 4 * 32, 32, 32);
			m_Atlas->AddFrame("opened", 5 * 32, 4 * 32, 32, 32);
			m_Atlas->SetFrame("closed");

			entity->AddComponent<DoorBehaviour>();
			Engine::GetInstance().Collision().AddToLayer("door", entity);
			return entity;
		}
	};
}