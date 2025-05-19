#include "AngryBirdDemo.h"
#include "Engine.h"
#include "Entity.h"
#include "Sprite.h"
#include "Atlas.h"
#include "RigidBody.h"
#include "Box.h"
#include "CircleCollider.h"
#include "Spawner.h"
#include "Button.h"
#include "AngryBirdController.h"
#include "Prefabs.h"

buki::AngryBirdDemo::AngryBirdDemo()
{
	Background = nullptr;
	BackgroundImage = nullptr;
	spawner = nullptr;
}

void buki::AngryBirdDemo::Load()
{
	spawner = Instantiate("spawner")->AddComponent<Spawner>();
	buki::Engine::GetInstance().Graphics().SetCameraPosition(Vector2::ZERO);
	Background = Instantiate("Background");
	BackgroundImage = Background->AddComponent<Atlas>();
	BackgroundImage->Load("assets/Kenney/Physics Assets/PNG/Backgrounds/colored_desert.png");
	
	spawner->AddPrototype("ButtonSimple", new ButtonSimple());

	CreateMenu();

}

void buki::AngryBirdDemo::OnWindowResize()
{
	//GroundAndBackground();
}

void buki::AngryBirdDemo::OnNotify(const std::string& button)
{
	if (button == "Ag_Lvl_1")
	{
		buki::Engine::GetInstance().World().SetLoadScene("Ag_Lvl_1");
	}
	if (button == "Ag_Lvl_2")
	{
		buki::Engine::GetInstance().World().SetLoadScene("Ag_Lvl_1");
	}
	if (button == "menu")
	{
		buki::Engine::GetInstance().World().SetLoadScene("Menu");
	}
}

void buki::AngryBirdDemo::OnStart()
{

}

void buki::AngryBirdDemo::OnStop()
{
	Background = nullptr;
	BackgroundImage = nullptr;
}


void buki::AngryBirdDemo::CreateMenu()
{
	Vector2 buttonsSize = Vector2(5.0f, 2.0f);
	float x, y;
	buki::Engine::GetInstance().Graphics().GetWindowSize(&x, &y);

	//BackgroundImage->Load("assets/Kenney/Physics Assets/PNG/Backgrounds/colored_grass.png");

	buki::Entity* lvl1ButtonEntity = spawner->Spawn("ButtonSimple", Vector2(0.0f, -5.0f), buttonsSize, 0.0f);
	Button* playlvl1Button = lvl1ButtonEntity->GetComponent<Button>();
	playlvl1Button->SetMessage("Ag_Lvl_1");
	playlvl1Button->SetButtonText("Level 1", 24);
	playlvl1Button->OnClick.AddListener(this);

	buki::Entity* lvl2ButtonEntity = spawner->Spawn("ButtonSimple", Vector2(0.0f, 0.0f), buttonsSize, 0.0f);
	Button* playlvl2Button = lvl2ButtonEntity->GetComponent<Button>();
	playlvl2Button->SetMessage("Ag_Lvl_2");
	playlvl2Button->SetButtonText("Level 2", 24);
	playlvl2Button->OnClick.AddListener(this);

	buki::Entity* menuButtonEntity = spawner->Spawn("ButtonSimple", Vector2(0.0f, 5.0f), buttonsSize, 0.0f);
	Button* menuButtonButton = menuButtonEntity->GetComponent<Button>();
	menuButtonButton->SetMessage("menu");
	menuButtonButton->SetButtonText("menu", 24);
	menuButtonButton->OnClick.AddListener(this);
}

