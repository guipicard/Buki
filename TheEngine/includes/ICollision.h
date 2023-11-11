#pragma once

#include <cstdlib>
#include <iostream>
#include "Entity.h"
#include <vector>
#include <string>

struct RectI;
namespace buki
{

	class ICollision
	{
	public:
		virtual ~ICollision() = default;
		virtual bool BoxColliding(std::string _name, int px, int py, int pw, int ph) = 0;
		virtual void AddLayer(std::string _name, std::vector<RectI> _layer) = 0;
		virtual void AddPlayer(Entity* _player) = 0;
		virtual void Update(float dt) = 0;
	};
}