#pragma once 
#include "IUpdatable.h"
#include "Observer.h"
#include "Component.h"
#include <string>
#include "Entity.h"

namespace buki
{
	class MonoBehaviour : public Observer<std::string, Entity*>, public IUpdatable
	{
	public:
		virtual ~MonoBehaviour() = default;
		/*virtual void Update(float dt) = 0;
		virtual void OnNotify(const int& value) = 0;*/
	};
}