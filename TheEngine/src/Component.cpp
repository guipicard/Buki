#include "Component.h"
#include "Engine.h"

buki::Component::Component(Entity* _entity)
	: m_Entity(_entity) 
{
}

buki::IInput& buki::Component::Input() const
{
	return buki::Engine::GetInstance()->Input();
}

buki::ILogger& buki::Component::Log() const
{
	return buki::Engine::GetInstance()->Log();
}

buki::IGraphics& buki::Component::Graphics() const
{
	return buki::Engine::GetInstance()->Graphics();
}

buki::IAudio& buki::Component::Audio() const
{
	return buki::Engine::GetInstance()->Audio();
}
