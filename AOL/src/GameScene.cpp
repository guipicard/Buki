#pragma once

#include "GameScene.h"
#include "Engine.h"
#include "Tilemap.h"
#include "Animation.h"
#include "Controller.h"
#include "Tilemap.h"
#include "CharacterSpawner.h"
#include "InteractObjSpawner.h"
#include "Spawner.h"
#include "Lolo.h"
#include "Chest.h"
#include "Heart.h"
#include "Atlas.h"
#include "Door.h"
#include "DoorBehaviour.h"
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
	

	InteractObjSpawner ISpawner;
	Chest* chestProto = new Chest();
	ISpawner.AddPrototype("chest", chestProto);
	Entity* chest = ISpawner.Spawn("chest", 5, 11);

	Heart* heartProto = new Heart();
	ISpawner.AddPrototype("heart", heartProto);
	ISpawner.Spawn("heart", 5, 3);
	ISpawner.Spawn("heart", 11, 6);

	Door* doorProto = new Door();
	ISpawner.AddPrototype("door", doorProto);
	Entity* door = ISpawner.Spawn("door", 7, 1);

	CharacterSpawner CSpawner;
	// PLAYER
	Lolo* loloProto = new Lolo(100);
	CSpawner.AddPrototype("Lolo", loloProto);
	int x = static_cast<int>(m_SpawnPoint.x);
	int y = static_cast<int>(m_SpawnPoint.y);
	Entity* player = CSpawner.Spawn("Lolo", x, y);
	player->GetComponent<BoxCollider>()->SetTilemap(m_Tilemap);

	Snakey* snakeyProto = new Snakey(0);
	CSpawner.AddPrototype("snakey", snakeyProto);
	Entity* snakey = CSpawner.Spawn("snakey", 7, 7);
	snakey->GetComponent<SnakeyBehaviour>()->SetPlayer(player);

	player->GetComponent<PlayerBehaviour>()->OnHeartPickup.AddListener(chest->GetComponent<ChestBehaviour>());
	player->GetComponent<PlayerBehaviour>()->OnKeyPickup.AddListener(door->GetComponent<DoorBehaviour>());
	player->GetComponent<PlayerBehaviour>()->SetHeart(2);
}
