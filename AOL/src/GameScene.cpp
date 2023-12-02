#pragma once

#include "GameScene.h"
#include "Engine.h"
#include "Tilemap.h"
#include "Animation.h"
#include "Controller.h"
#include "Tilemap.h"
#include "Spawner.h"
#include "Lolo.h"
#include "Chest.h"
#include "Heart.h"
#include "Atlas.h"
#include "Door.h"
#include "DoorBehaviour.h"
#include "Prototypes.h"
#include "Snakey.h"

using namespace buki;

GameScene::GameScene()
{
	mumu = Engine::GetInstance().Audio().LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = Engine::GetInstance().Audio().LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");
	m_SpawnPoint = Point2D(1.0f, 6.0f);
}

void GameScene::Load()
{
	Engine::GetInstance().Audio().PlayMusic(mumu);
	// MAP
	Entity* m_Map = Instantiate("map");
	Tilemap* m_Tilemap = m_Map->AddComponent<Tilemap>();
	m_Tilemap->Load("./assets/env.png", 13, 14, 32, 32);
	TLayer groundLayer = m_Tilemap->CreateLayerFromCSV("./levels/1/floor1-1._ground.csv");
	TLayer wallsLayer = m_Tilemap->CreateLayerFromCSV("./levels/1/floor1-1._walls.csv");
	TLayer treesLayer = m_Tilemap->CreateLayerFromCSV("./levels/1/floor1-1._trees.csv");
	m_Tilemap->AddLayer("ground", groundLayer, false);
	m_Tilemap->AddLayer("walls", wallsLayer, true);
	m_Tilemap->AddLayer("trees", treesLayer, true);
	

	Spawner* spawner = m_Map->AddComponent<Spawner>();
	Chest* chestProto = new Chest();
	spawner->AddPrototype("chest", chestProto);
	Entity* chest = spawner->Spawn("chest", 5, 11);

	Heart* heartProto = new Heart();
	spawner->AddPrototype("heart", heartProto);
	spawner->Spawn("heart", 5, 3);
	Entity* heart = spawner->Spawn("heart", 11, 6);
	heart->GetComponent<HeartBehaviour>()->Charged();

	Door* doorProto = new Door();
	spawner->AddPrototype("door", doorProto);
	Entity* door = spawner->Spawn("door", 7, 1);

	// PLAYER
	Lolo* loloProto = new Lolo(100);
	spawner->AddPrototype("Lolo", loloProto);
	int x = static_cast<int>(m_SpawnPoint.x);
	int y = static_cast<int>(m_SpawnPoint.y);
	Entity* player = spawner->Spawn("Lolo", x, y);
	player->GetComponent<BoxCollider>()->SetTilemap(m_Tilemap);

	Snakey* snakeyProto = new Snakey(0);
	spawner->AddPrototype("snakey", snakeyProto);
	Entity* snakey = spawner->Spawn("snakey", 7, 7);
	snakey->GetComponent<SnakeyBehaviour>()->SetPlayer(player);
	snakey->GetComponent<BoxCollider>()->SetTilemap(m_Tilemap);

	player->GetComponent<PlayerBehaviour>()->OnHeartPickup.AddListener(chest->GetComponent<ChestBehaviour>());
	player->GetComponent<PlayerBehaviour>()->OnKeyPickup.AddListener(door->GetComponent<DoorBehaviour>());
	player->GetComponent<PlayerBehaviour>()->SetHeart(2);
}
