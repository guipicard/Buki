#include "InteractObjSpawner.h"

buki::Entity* buki::InteractObjSpawner::Spawn(const std::string& name, int x, int y)
{
	if (m_Prototypes.count(name) > 0)
	{
		return m_Prototypes[name]->Clone(x, y);
	}
	return nullptr;
}
