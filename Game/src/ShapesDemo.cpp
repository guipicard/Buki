#pragma once
#include "ShapesDemo.h"
#include "Engine.h"
#include "Animation.h"
#include "Spawner.h"
#include "Prototypes.h"
#include "Player.h"
#include "CircleCollider.h"
#include "Box.h"
#include "Circle.h"
#include "Sprite.h"
#include "Atlas.h"
#include "RigidBody.h"
#include "Text.h"
#include "ShapesController.h"
#include "Button.h"
#include "Camera.h"

using namespace buki;

ShapesDemo::ShapesDemo()
{
	Ground = nullptr;
	GroundSprite = nullptr;
	Background = nullptr;
	BackgroundImage = nullptr;
}

void ShapesDemo::Load()
{
	buki::Engine::GetInstance().Graphics().SetCameraPosition(Vector2::ZERO);
	Background = Instantiate("Background");
	BackgroundImage = Background->AddComponent<Atlas>();
	Ground = Instantiate("Ground");
	RigidBody* GroundRB = Ground->AddComponent<RigidBody>();
	Box* GroundCollider = Ground->AddComponent<Box>();
	GroundSprite = Ground->AddComponent<Atlas>();
	GroundSprite->Load("assets/Kenney/Physics Assets/PNG/Other/grass.png");

	GroundAndBackground();

	GroundRB->Type = RigidBody::BodyType::Static;
	GroundRB->FixedRotation = true;
	GroundCollider->Collider.Density = 1.0f;
	GroundCollider->Collider.Friction = 0.3f;
	GroundCollider->Collider.Size = Ground->GetTransform()->GetSize() / 2;
	Ground->ActivatePhysics();

	////debug text
	Entity* playerTextEntity = Instantiate("velocityx");
	Text* leftText = playerTextEntity->AddComponent<Text>();
	leftText->LoadText("./fonts/Kenney/Kenney-Bold-modified.ttf", 18);
	leftText->SetText("Left click to Spawn a Circle");
	Vector2 leftSize = leftText->GetSize();
	playerTextEntity->GetTransform()->SetPosition(Vector2(1.0f + leftSize.x / 2, 1.0f + leftSize.y));

	Entity* playerEntityX = Instantiate("velocityy");
	Text* rightText = playerEntityX->AddComponent<Text>();
	rightText->LoadText("./fonts/Kenney/Kenney-Bold-modified.ttf", 18);
	rightText->SetText("Right click to spawn a Rectangle");
	Vector2 rightSize = leftText->GetSize();
	playerEntityX->GetTransform()->SetPosition(Vector2(1.0f + rightSize.x / 2, (1.0f + leftSize.y) * 2));

	Entity* controller = Instantiate("controller");
	controller->AddComponent<ShapesController>();

	Vector2 buttonsSize = Vector2(1.0f, 0.5f);
	Camera* camera = buki::Engine::GetInstance().Graphics().GetCamera();
	Vector2 cameraPos = camera->position;
	Vector2 cameraSize = { camera->width, camera->height };
	cameraSize /= METRES_TO_PIXELS;
	//Vector2 ButtonPos = { 0.0f,0.0f};
	Vector2 ButtonPos = { -cameraSize / 2 };
	ButtonPos += {1.0f,1.0f};

	buki::Entity* BoxBothEntity = Instantiate("BoxBoth");
	Button* BoxBothButton = BoxBothEntity->AddComponent<Button>();
	BoxBothButton->SetMessage("BoxBoth");
	BoxBothButton->SetbuttonFont("./fonts/droid_sans.ttf");
	BoxBothButton->SetButtonText("Box Both", 18);
	BoxBothEntity->GetTransform()->SetSize(buttonsSize);
	BoxBothEntity->GetTransform()->SetPosition(ButtonPos);
	BoxBothButton->OnClick.AddListener(this);

	ButtonPos.x += 3.0f;

	buki::Entity* BoxDrawEntity = Instantiate("BoxDraw");
	Button* BoxDrawButton = BoxDrawEntity->AddComponent<Button>();
	BoxDrawButton->SetMessage("BoxDraw");
	BoxDrawButton->SetbuttonFont("./fonts/droid_sans.ttf");
	BoxDrawButton->SetButtonText("Box Draw", 18);
	BoxDrawEntity->GetTransform()->SetSize(buttonsSize);
	BoxDrawEntity->GetTransform()->SetPosition(ButtonPos);
	BoxDrawButton->OnClick.AddListener(this);

	ButtonPos.x += 3.0f;

	buki::Entity* BoxFillEntity = Instantiate("BoxFill");
	Button* BoxFillButton = BoxFillEntity->AddComponent<Button>();
	BoxFillButton->SetMessage("BoxFill");
	BoxFillButton->SetbuttonFont("./fonts/droid_sans.ttf");
	BoxFillButton->SetButtonText("Box Fill", 18);
	BoxFillEntity->GetTransform()->SetSize(buttonsSize);
	BoxFillEntity->GetTransform()->SetPosition(ButtonPos);
	BoxFillButton->OnClick.AddListener(this);


	ButtonPos.x -= 6.0f;
	ButtonPos.y += 3.0f;

	buki::Entity* CircleBothEntity = Instantiate("CircleBoth");
	Button* CircleBothButton = CircleBothEntity->AddComponent<Button>();
	CircleBothButton->SetMessage("CircleBoth");
	CircleBothButton->SetbuttonFont("./fonts/droid_sans.ttf");
	CircleBothButton->SetButtonText("Circle Both", 18);
	CircleBothEntity->GetTransform()->SetSize(buttonsSize);
	CircleBothEntity->GetTransform()->SetPosition(ButtonPos);
	CircleBothButton->OnClick.AddListener(this);

	ButtonPos.x += 3.0f;

	buki::Entity* CircleDrawEntity = Instantiate("CircleDraw");
	Button* CircleDrawButton = CircleDrawEntity->AddComponent<Button>();
	CircleDrawButton->SetMessage("CircleDraw");
	CircleDrawButton->SetbuttonFont("./fonts/droid_sans.ttf");
	CircleDrawButton->SetButtonText("Circle Draw", 18);
	CircleDrawEntity->GetTransform()->SetSize(buttonsSize);
	CircleDrawEntity->GetTransform()->SetPosition(ButtonPos);
	CircleDrawButton->OnClick.AddListener(this);

	ButtonPos.x += 3.0f;

	buki::Entity* CircleFillEntity = Instantiate("CircleFill");
	Button* CircleFillButton = CircleFillEntity->AddComponent<Button>();
	CircleFillButton->SetMessage("CircleFill");
	CircleFillButton->SetbuttonFont("./fonts/droid_sans.ttf");
	CircleFillButton->SetButtonText("Circle Fill", 18);
	CircleFillEntity->GetTransform()->SetSize(buttonsSize);
	CircleFillEntity->GetTransform()->SetPosition(ButtonPos);
	CircleFillButton->OnClick.AddListener(this);
}

void buki::ShapesDemo::OnWindowResize()
{
}

void buki::ShapesDemo::OnNotify(const std::string& button)
{
	if (button == "BoxBoth")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Box* box = e->GetComponent<Box>();
			if (box)
			{
				box->DebugDraw = true;
				box->DrawShape = true;
			}
		}
	}
	if (button == "BoxDraw")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Box* box = e->GetComponent<Box>();
			if (box)
			{
				box->DebugDraw = true;
				box->DrawShape = false;
			}
		}
	}
	if (button == "BoxFill")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Box* box = e->GetComponent<Box>();
			if (box)
			{
				box->DebugDraw = false;
				box->DrawShape = true;
			}
		}
	}

	if (button == "CircleBoth")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Circle* circle = e->GetComponent<Circle>();
			if (circle)
			{
				circle->DebugDraw = true;
				circle->DrawShape = true;
			}
		}
	}
	if (button == "CircleDraw")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Circle* circle = e->GetComponent<Circle>();
			if (circle)
			{
				circle->DebugDraw = true;
				circle->DrawShape = false;
			}
		}
	}
	if (button == "CircleFill")
	{
		for each(auto e  in buki::Engine::GetInstance().World().GetEntitiesInWorld())
		{
			Circle* circle = e->GetComponent<Circle>();
			if (circle)
			{
				circle->DebugDraw = false;
				circle->DrawShape = true;
			}
		}
	}
}

void buki::ShapesDemo::GroundAndBackground()
{
	Engine::GetInstance().Log().LogMessage("shapes");
	float intWindowW, intWindowH;
	buki::Engine::GetInstance().Graphics().GetWindowSize(&intWindowW, &intWindowH);
	Vector2 windowSize = Vector2(intWindowW, intWindowH);
	Background->GetTransform()->SetPosition(Vector2::ZERO);
	float groundWidth = windowSize.x - 6.0f;
	Vector2 bgTileSize = { windowSize.y, windowSize.y };
	Vector2 groundTileSize = { 1.0f, 1.0f };
	Vector2 groundPos = { 0.0f, windowSize.y / 2 - (groundTileSize.y / 2) };

	int imgX, imgY;

	Ground->GetTransform()->SetPosition(groundPos);
	GroundSprite->SetSize(groundTileSize);
	GroundSprite->GetTextureSize(&imgX, &imgY);
	GroundSprite->AddSource("ground", RectI{ 0,0, imgX, imgY });
	int tileNum = (int)(groundWidth / groundTileSize.x);
	GroundSprite->SetTileSize(tileNum, 1);
	Ground->GetTransform()->SetSize(Vector2(groundTileSize.x * tileNum, groundTileSize.y));
	for (int i = 0; i < tileNum; i++)
	{
		GroundSprite->AddDestination("ground", i, 0);
	}
}