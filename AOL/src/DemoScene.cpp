#include "DemoScene.h"
#include "Engine.h"
#include "Engine.h"
#include "Entity.h"
#include "Atlas.h"
#include "Controller.h"

DemoScene::DemoScene()
{
	m_Entity1 = nullptr;
	m_Player = nullptr;
	mumu = buki::Engine::GetInstance()->Audio().LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = buki::Engine::GetInstance()->Audio().LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");
}

void DemoScene::Load()
{
	buki::Engine::GetInstance()->Audio().PlayMusic(mumu);
	m_Entity1 = Instantiate("map");
	m_Entity1->AddComponent<Atlas>();
	Atlas* _atlas = m_Entity1->GetComponent<Atlas>();
	_atlas->SetPath("./assets/env.png");
	_atlas->LoadTileset("./assets/env.png", 32, 32, 36, 540);
	_atlas->SetLayerLength(25);
	TLayer waterLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Eau.csv");
	TLayer groundLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Ground.csv");
	TLayer treesLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Trees.csv");
	_atlas->AddLayer("water", waterLayer);
	_atlas->AddLayer("ground", groundLayer);
	_atlas->AddLayer("trees", treesLayer);

	Entity* m_Player = Instantiate("player");
	m_Player->SetPos(Point2D(60, 60));
	m_Player->SetSize(Point2D(32, 32));
	m_Player->AddComponent<Sprite>();
	Sprite* _sprite = m_Player->GetComponent<Sprite>();
	_sprite->SetPath("./assets/lolo.png");
	_sprite->SetSrc(RectI(0, 0, 32, 32));
	m_Player->AddComponent<Controller>();
}
