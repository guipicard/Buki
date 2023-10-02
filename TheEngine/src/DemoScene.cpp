#include "DemoScene.h"
#include "Engine.h"
#include "Square.h"
#include "Controller.h"
#include "Image.h"

buki::DemoScene::DemoScene()
{
	m_Entity1 = buki::Engine::GetInstance()->World().Create("square 1", 50.0f, 50.0f, 50.0f, 50.0f);

}

buki::DemoScene::~DemoScene()
{
}

void buki::DemoScene::Load()
{
	m_Entity1 = buki::Engine::GetInstance()->World().Create("square 1", 50.0f, 50.0f, 50.0f, 50.0f);

	m_Entity1->AddComponent<Square>();
	m_Entity1->AddComponent<Controller>();

	m_Entity1->GetComponent<Square>()->SetColor(buki::Color::Blue);
}
