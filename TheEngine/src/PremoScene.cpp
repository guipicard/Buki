#include "PremoScene.h"
#include "Engine.h"
#include "Square.h"
#include "Controller.h"
#include "Image.h"

buki::PremoScene::PremoScene()
{
	m_Entity1 = buki::Engine::GetInstance()->World().Create("square 3", 150.0f, 150.0f, 50.0f, 50.0f);
}

buki::PremoScene::~PremoScene()
{
}

void buki::PremoScene::Load()
{
	m_Entity1 = buki::Engine::GetInstance()->World().Create("square 3", 150.0f, 150.0f, 50.0f, 50.0f);

	m_Entity1->AddComponent<Square>();
	m_Entity1->AddComponent<Controller>();
	m_Entity1->AddComponent<Image>();

	m_Entity1->GetComponent<Square>()->SetColor(buki::Color::Blue);
	m_Entity1->GetComponent<Image>()->SetPath("./assets/pika.jpeg");
}
