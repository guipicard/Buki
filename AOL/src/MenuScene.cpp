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
	textEntity->AddComponent<Text>();
	Text* text = textEntity->GetComponent<Text>();
	size_t _fontid = buki::Engine::GetInstance().Graphics().LoadFont("./fonts/vinque rg.otf", 160);
	text->SetText("Press Enter To Switch Scenes");
	Square* _square = textEntity->AddComponent<Square>();
	_square->SetColor(Color::GREEN);
	int _w, _h;
	buki::Engine::GetInstance().Graphics().GetTextSize("Press Enter To Switch Scenes", _fontid, &_w, &_h);
	_square->SetSize(_w, _h);
}
