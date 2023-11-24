#include "Component.h"
#include "Engine.h"

buki::Component::Component() : Component(nullptr)
{
}

buki::Component::Component(Entity* _entity) : m_Entity(_entity) 
{
}

buki::IInput& buki::Component::Input() const
{
	return Engine::GetInstance().Input();
}

buki::ILogger& buki::Component::Log() const
{
	return Engine::GetInstance().Log();
}

buki::IGraphics& buki::Component::Graphics() const
{
	return Engine::GetInstance().Graphics();
}

buki::IAudio& buki::Component::Audio() const
{
	return Engine::GetInstance().Audio();
}

buki::ICollision& buki::Component::Collision() const
{
	return buki::Engine::GetInstance().Collision();
}

buki::IWorld& buki::Component::World() const
{
	return Engine::GetInstance().World();
}
