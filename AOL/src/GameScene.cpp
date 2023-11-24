#pragma once

#include "GameScene.h"
#include "Engine.h"
#include "Tilemap.h"
#include "Animation.h"
#include "Controller.h"
#include "Tilemap.h"

using namespace buki;

GameScene::GameScene()
{
	mumu = Engine::GetInstance().Audio().LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = Engine::GetInstance().Audio().LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");
}

void GameScene::Load()
{
	Engine::GetInstance().Audio().PlayMusic(mumu);
	// MAP
	m_Map = Instantiate("map");
	m_Tilemap = m_Map->AddComponent<Tilemap>();
	m_Tilemap->Load("./assets/env.png", 25, 19, 32, 32);
	TLayer waterLayer = m_Tilemap->CreateLayerFromCSV("./assets/AOL_Eau.csv");
	TLayer groundLayer = m_Tilemap->CreateLayerFromCSV("./assets/AOL_Ground.csv");
	TLayer wallsLayer = m_Tilemap->CreateLayerFromCSV("./assets/AOL_Walls.csv");
	TLayer treesLayer = m_Tilemap->CreateLayerFromCSV("./assets/AOL_Trees.csv");
	m_Tilemap->AddLayer("water", waterLayer);
	m_Tilemap->AddLayer("ground", groundLayer);
	m_Tilemap->AddLayer("walls", wallsLayer);
	m_Tilemap->AddLayer("trees", treesLayer);

	// PLAYER

	m_Player = Instantiate("player");
	m_Player->SetPos(Point2D(80, 80));
	m_Player->SetSize(Point2D(32, 32));
	m_Anim = m_Player->AddComponent<Animation>();
	m_Anim->Load("./assets/lolo.png");
	// move anims
	m_Anim->Init(7, 32, 32);
	m_Anim->AddClip("move_down", 0, 5, 0.2f);
	m_Anim->AddClip("move_left", 7, 5, 0.2f);
	m_Anim->AddClip("move_up", 14, 5, 0.2f);
	m_Anim->AddClip("move_right", 21, 5, 0.2f);
	// idle anims
	m_Anim->AddClip("idle_down", 5, 2, 0.2f);
	m_Anim->AddClip("idle_left", 12, 2, 0.2f);
	m_Anim->AddClip("idle_up", 19, 2, 0.2f);
	m_Anim->AddClip("idle_right", 26, 2, 0.2f);
	//death clip
	m_Anim->AddClip("death", 28, 4, 0.4f);

	m_Anim->Play("idle_down", true);
	m_Controller = m_Player->AddComponent<Controller>();
	m_Controller->SetSpeed(50.0f);
}

void GameScene::Update(float dt)
{
	if (m_Player == nullptr) return;
	int _collider;
	Point2D playerPos;
	Point2D playerSize;
	m_Player->GetPosition(&playerPos);
	m_Player->GetSize(&playerSize);
	if (m_Tilemap->IsColliding("water", playerPos.x, playerPos.y, playerSize.x, playerSize.y, &_collider))
	{
		m_Controller->LockController();
		m_Anim->Play("death", false);
		if (m_Anim->IsStopped())
		{
			Engine::GetInstance().World().Remove(m_Player);
			m_Player = nullptr;
		}
	}
	else if (m_Tilemap->IsColliding("trees", playerPos.x, playerPos.y, playerSize.x, playerSize.y, &_collider))
	{
		Point2D _oldPos = Point2D();
		m_Player->GetOldPos(&_oldPos);
		m_Player->SetPos(_oldPos);
	}
	else if (m_Tilemap->IsColliding("walls", playerPos.x, playerPos.y, playerSize.x, playerSize.y, &_collider))
	{
		Point2D _oldPos = Point2D();
		m_Player->GetOldPos(&_oldPos);
		m_Player->SetPos(_oldPos);
	}
}
