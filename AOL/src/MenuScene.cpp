#pragma once

#include "MenuScene.h"
#include "Engine.h"
#include "Text.h"

MenuScene::MenuScene()
{
}

void MenuScene::Load()
{
	buki::Entity* textEntity = Instantiate("text");
	textEntity->AddComponent<Text>();
	Text* text = textEntity->GetComponent<Text>();
	buki::Engine::GetInstance().Graphics().LoadFont("./fonts/vinque rg.otf", 32);
	text->SetText("Press Enter To Switch Scenes");
}
