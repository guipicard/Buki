#pragma once
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include "Entity.h"
#include "IScene.h"

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
		virtual Entity* Create(const std::string& name, float _x, float _y, float _h, float _w) = 0;
		virtual void Add(Entity* _entity) = 0;
		virtual void Remove(Entity* _entity) = 0;
		virtual void Find() = 0;
		virtual void Load(const std::string& scene) = 0;
		virtual void Unload() = 0;
		virtual void Register(const std::string& name, IScene* scene) = 0;
		virtual void SetCurrentSceneName(std::string _name) = 0;
		virtual IScene* GetCurrentScene() = 0;
		virtual std::string GetCurrentSceneName() = 0;
	};
}