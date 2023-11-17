#pragma once

#include "GameScene.h"
#include "Engine.h"
#include "Atlas.h"
#include "Animation.h"
#include "Controller.h"

GameScene::GameScene()
{
	mumu = buki::Engine::GetInstance()->Audio().LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = buki::Engine::GetInstance()->Audio().LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");
}

void GameScene::Load()
{
	buki::Engine::GetInstance()->Audio().PlayMusic(mumu);
	buki::Entity* m_Map = Instantiate("map");
	m_Map->AddComponent<Atlas>();
	Atlas* _atlas = m_Map->GetComponent<Atlas>();
	_atlas->LoadTileset("./assets/env.png", 32, 32, 36, 540);
	TLayer waterLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Eau.csv");
	TLayer groundLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Ground.csv");
	TLayer wallsLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Walls.csv");
	TLayer treesLayer = _atlas->CreateLayerFromCSV("./assets/AOL_Trees.csv");
	_atlas->AddLayer("water", waterLayer);
	_atlas->AddLayer("ground", groundLayer);
	_atlas->AddLayer("Walls", wallsLayer);
	_atlas->AddLayer("trees", treesLayer);

	buki::Entity* m_Player = Instantiate("player");
	m_Player->SetPos(Point2D(80, 80));
	//m_Player->SetOldPos(Point2D(60, 60));
	m_Player->SetSize(Point2D(32, 32));
	m_Player->AddComponent<Animation>();
	Animation* _anim = m_Player->GetComponent<Animation>();
	_anim->SetPath("./assets/lolo.png");
	// move anims
	_anim->Init(5, 32, 32);
	_anim->AddClip("move_down", 0, 5, 0, 0.2f);
	_anim->AddClip("move_left", 0, 5, 1, 0.2f);
	_anim->AddClip("move_up", 0, 5, 2, 0.2f);
	_anim->AddClip("move_right", 0, 5, 3, 0.2f);
	// idle anims
	_anim->Init(2, 32, 32);
	_anim->AddClip("idle_down", 5, 2, 0, 0.2f);
	_anim->AddClip("idle_left", 5, 2, 1, 0.2f);
	_anim->AddClip("idle_up", 5, 2, 2, 0.2f);
	_anim->AddClip("idle_right", 5, 2, 3, 0.2f);
	//death clip
	_anim->Init(4, 32, 32);
	_anim->AddClip("death", 0, 4, 4, 0.4f);

	_anim->Play("idle_down", true);
	m_Player->AddComponent<Controller>();

	//buki::Engine::GetInstance()->Collision().AddPlayer(m_Player);
}
