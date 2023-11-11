#pragma once

#include "ICollision.h"
#include <map>
#include <vector>

struct RectI;
class Entity;

namespace buki
{
	class CollisionService : public ICollision
	{
	public:
		CollisionService();
		virtual ~CollisionService();
		virtual bool BoxColliding(std::string _name, int px, int py, int pw, int ph) override;
		virtual void AddLayer(std::string _name, std::vector<RectI> _layer) override;
		virtual void AddPlayer(Entity* _player) override;
		virtual void Update(float dt) override;
		void Draw();
	private:
		std::map<std::string, std::vector<RectI>> m_TileMap;
		Entity* m_Player = nullptr;
		bool m_PlayerDead = false;
	};
}
