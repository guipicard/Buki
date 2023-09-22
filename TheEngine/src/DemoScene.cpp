#include "DemoScene.h"
#include "Square.h"
#include "Engine.h"

void buki::DemoScene::Load()
{
	buki::Entity* m_Entity1 = new Square("first", 50, 50, 50, 50, Color::Red);
	buki::Entity* m_Entity2 = new Square("second", 100, 100, 100, 100, Color::Blue);


	buki::Engine::GetInstance()->World().Add(m_Entity1);
	buki::Engine::GetInstance()->World().Add(m_Entity2);
}

void buki::DemoScene::Load2()
{
	buki::Entity* m_Entity1 = new Square("first", 150, 150, 150, 150, Color::Green);
	buki::Entity* m_Entity2 = new Square("second", 200, 200, 200, 200, Color::White);

	buki::Engine::GetInstance()->World().Add(m_Entity1);
	buki::Engine::GetInstance()->World().Add(m_Entity2);
}
