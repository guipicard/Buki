#pragma once

#include "ICollision.h"
#include <map>
#include <vector>

namespace buki
{
	class CollisionService : public ICollision
	{
	public:
		virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) override;
		virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) override;
		virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) override;
		virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) override;
		virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) override;
		virtual void AddToLayer(const std::string& layerName, Entity* entity) override;
		virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other) override;
		virtual void Remove(Entity* entity) override;
	private:
		std::map<std::string, std::vector<Entity*>> m_Layers;
	};
}
