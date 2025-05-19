#pragma once
#include "Prefabs.h"
#include "Engine.h"
#include "Component.h"
#include "Sprite.h"
#include "Circle.h"
#include "Box.h"
#include "RigidBody.h"
#include "Button.h"
#include "Text.h"

buki::Entity* buki::CircleShape::Clone(Vector2 position, Vector2 size, float rotation)
{
	number++;
	std::string name = "circle" + std::to_string(number);
	Entity* circleEntity = Engine::GetInstance().World().Create(name);
	int radius = rand() % 6 +2;
	float r = (float)radius;
	r /= 4;
	float rot = static_cast<float>((rand() % 7000) / 1000.0f);
	Vector2 randomSize = Vector2(r, r);
	circleEntity->Initialize(position, 0.0f, randomSize);

	Circle* col = circleEntity->AddComponent<Circle>();
	col->Collider.Density = 1.0f;
	col->Collider.Friction = 0.3f;
	//col->Collider.RestitutionThreshold = 0.9f;
	col->Collider.Radius = r /2;
	col->ShapeColor = Color::LIGHTCORAL;
	col->DebugColor = Color::RED;
	col->DrawShape = true;
	col->DebugDraw = true;

	circleEntity->ActivatePhysics();

	return circleEntity;
}

buki::Entity* buki::RectangleShape::Clone(Vector2 position, Vector2 size, float rotation)
{
	number++;
	std::string name = "rect" + std::to_string(number);
	Entity* rectEntity = Engine::GetInstance().World().Create(name);
	int sizeX = rand() % 10 + 2;
	int sizeY = rand() % 10 + 2;
	float rot = static_cast<float>((rand() % 7000) / 1000.0f);
	Vector2 randomSize = Vector2(sizeX, sizeY) / 5;
	rectEntity->Initialize(position, rot, randomSize);

	Box* col = rectEntity->AddComponent<Box>();
	col->Collider.Density = 1.0f;
	col->Collider.Friction = 0.3f;
	//col->Collider.RestitutionThreshold = 0.9f;
	col->Collider.Size = randomSize / 2;
	col->ShapeColor = Color::LIGHTGREEN;
	col->DebugColor = Color::GREEN;
	col->DrawShape = true;
	col->DebugDraw = true;

	rectEntity->ActivatePhysics();

	return rectEntity;
}

buki::Entity* buki::StoneSlim::Clone(Vector2 position, Vector2 size, float rotation)
{
	number++;
	std::string name = "StoneSlim" + std::to_string(number);
	Entity* rectEntity = Engine::GetInstance().World().Create(name);
	rectEntity->Initialize(position, rotation, size);

	Sprite* m_Sprite = rectEntity->AddComponent<Sprite>();
	m_Sprite->Load("./assets/Kenney/Physics Assets/PNG/Stone elements/elementStone020.png");

	Box* col = rectEntity->AddComponent<Box>();
	col->Collider.Density = 1.0f;
	col->Collider.Friction = 0.4f;
	col->Collider.Restitution = 0.3f;
	col->Collider.Size = size / 2;
	
	rectEntity->ActivatePhysics();

	return rectEntity;
}

buki::Entity* buki::Bird::Clone(Vector2 position, Vector2 size, float rotation)
{
	number++;
	std::string name = "bird" + std::to_string(number);
	Entity* bird = Engine::GetInstance().World().Create(name);
	bird->GetTransform()->SetPosition(position);
	bird->GetTransform()->SetSize(size);
	bird->GetTransform()->SetRotation(rotation);
	bird->SetZ(1);
	Sprite* birdImg = bird->AddComponent<Sprite>();
	birdImg->Load("./assets/Kenney/Physics Assets/PNG/Aliens/alienGreen_round.png");
	Circle* col = bird->AddComponent<Circle>();
	col->Collider.Density = 1.0f;
	col->Collider.Friction = 0.3f;
	col->Collider.Restitution = 0.5f;
	col->Collider.Radius = bird->GetTransform()->GetSize().x / 2.0f;
	return bird;
}

buki::Entity* buki::ButtonSimple::Clone(Vector2 position, Vector2 size, float rotation)
{
	number++;
	std::string name = "ButtonSimple" + std::to_string(number);
	Entity* button = Engine::GetInstance().World().Create(name);
	//button->SetZ(10);
	Button* buttonCmp = button->AddComponent<Button>();
	button->GetTransform()->SetSize(size);
	button->GetTransform()->SetPosition(position);
	buttonCmp->SetbuttonFont("./assets/Kenney/Fonts/Kenney Blocks.ttf");
	buttonCmp->SetButtonText("Button Simple", 24);
	buttonCmp->SetImage("./assets/Kenney/MiniGame/Ui/miniguide5_button.png");
	buttonCmp->GetText()->SetColor(Color::BLACK);
	buttonCmp->GetText()->SetPosition({ 0.0f, -0.15f });
	buttonCmp->SetFitToText(false);
	return button;
}
