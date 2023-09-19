#pragma once
#include <cstdlib>
#include <iostream>
#include "Entity.h"

namespace buki
{
	class IWorld
	{
	public:
		virtual ~IWorld() = default;
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void Destroy() = 0;
		virtual void Add(Entity* _entity) = 0;
		virtual void Remove(Entity* _entity) = 0;
		virtual void Find() = 0;

	};
}