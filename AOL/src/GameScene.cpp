#pragma once

#include "GameScene.h"
#include "Engine.h"
#include "Tilemap.h"
#include "Animation.h"
#include "Controller.h"

GameScene::GameScene()
{
	mumu = buki::Engine::GetInstance().Audio().LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = buki::Engine::GetInstance().Audio().LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");
	m_Player = nullptr;
	m_Map = nullptr;
}

void GameScene::Load()
{
	buki::Engine::GetInstance().Audio().PlayMusic(mumu);
	// MAP
	m_Map = Instantiate("map");
	Tilemap* _tilemap = m_Map->AddComponent<Tilemap>();
	_tilemap->Load("./assets/env.png", 25, 19, 32, 32);
	TLayer waterLayer = _tilemap->CreateLayerFromCSV("./assets/AOL_Eau.csv");
	TLayer groundLayer = _tilemap->CreateLayerFromCSV("./assets/AOL_Ground.csv");
	TLayer wallsLayer = _tilemap->CreateLayerFromCSV("./assets/AOL_Walls.csv");
	TLayer treesLayer = _tilemap->CreateLayerFromCSV("./assets/AOL_Trees.csv");
	_tilemap->AddLayer("water", waterLayer);
	_tilemap->AddLayer("ground", groundLayer);
	_tilemap->AddLayer("Walls", wallsLayer);
	_tilemap->AddLayer("trees", treesLayer);

	// PLAYER

	m_Player = Instantiate("player");
	m_Player->SetPos(Point2D(80, 80));
	//m_Player->SetOldPos(Point2D(60, 60));
	m_Player->SetSize(Point2D(32, 32));
	m_Player->AddComponent<Animation>();
	Animation* _anim = m_Player->GetComponent<Animation>();
	_anim->Load("./assets/lolo.png");
	// move anims
	_anim->Init(7, 32, 32);
	_anim->AddClip("move_down", 0, 5, 0.2f);
	_anim->AddClip("move_left", 7, 5, 0.2f);
	_anim->AddClip("move_up", 14, 5, 0.2f);
	_anim->AddClip("move_right", 21, 5, 0.2f);
	// idle anims
	_anim->AddClip("idle_down", 5, 2, 0.2f);
	_anim->AddClip("idle_left", 12, 2, 0.2f);
	_anim->AddClip("idle_up", 19, 2, 0.2f);
	_anim->AddClip("idle_right", 26, 2, 0.2f);
	//death clip
	_anim->AddClip("death", 0, 4, 0.4f);

	_anim->Play("idle_down", true);
	m_Player->AddComponent<Controller>();
}

void GameScene::Update(float dt)
{

	if ()
	{

	}
}
