#pragma once

#include "MenuScene.h"
#include "Engine.h"
#include "Text.h"
#include "Square.h"
#include "Point2D.h"
#include "PlayButton.h"

MenuScene::MenuScene()
{
}

void MenuScene::Load()
{
	int windowW = 0;
	int windowH = 0;

	buki::Entity* TitleEntity = Instantiate("Title");
	Text* TitleText = TitleEntity->AddComponent<Text>();
	TitleText->LoadText("./fonts/vinque rg.otf", 36);
	TitleText->SetText("Press Enter To Switch Scenes");
	Engine::GetInstance().Graphics().GetWindowSize(&windowW, &windowH);
	TitleEntity->SetPos(Point2D((windowW / 2) - (TitleText->GetW() / 2), (windowH / 4) - (TitleText->GetH() / 2)));

	buki::Entity* PlayEntity = Instantiate("PlayButton");
	Text* PlayText = PlayEntity->AddComponent<Text>();
	PlayText->LoadText("./fonts/vinque rg.otf", 24);
	PlayText->SetText("Play");
	Engine::GetInstance().Graphics().GetWindowSize(&windowW, &windowH);
	PlayEntity->SetPos(Point2D((windowW / 2) - (PlayText->GetW() / 2), (windowH / 2) - (PlayText->GetH() / 2)));

	buki::Entity* QuitEntity = Instantiate("QuitButton");
	Text* QuitText = QuitEntity->AddComponent<Text>();
	QuitText->LoadText("./fonts/vinque rg.otf", 24);
	QuitText->SetText("Quit");
	Engine::GetInstance().Graphics().GetWindowSize(&windowW, &windowH);
	QuitEntity->SetPos(Point2D((windowW / 2) - (QuitText->GetW() / 2), (windowH) - (QuitText->GetH() * 2)));

	PlayEntity->AddComponent<PlayButton>();

}
