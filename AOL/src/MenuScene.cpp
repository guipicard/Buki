#pragma once

#include "MenuScene.h"
#include "Engine.h"
#include "Text.h"
#include "Square.h"

MenuScene::MenuScene()
{
}

void MenuScene::Load()
{
	buki::Entity* textEntity = Instantiate("text");
	Text* text = textEntity->AddComponent<Text>();
	text->Load("./fonts/vinque rg.otf");
	text->SetText("Press Enter To Switch Scenes");
	/*Square* _square = textEntity->AddComponent<Square>();
	_square->SetColor(Color::GREEN);
	int _w, _h;
	buki::Engine::GetInstance().Graphics().GetTextSize("Press Enter To Switch Scenes", _fontid, &_w, &_h);
	_square->SetSize(_w, _h);*/
}

void MenuScene::Update(float dt)
{
}
