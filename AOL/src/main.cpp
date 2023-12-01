#define win32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"
#include "GameScene.h"
#include "MenuScene.h"

using namespace buki;

void InitGameplay(void) {
	Engine::GetInstance().World().Register("Game", new GameScene());
	Engine::GetInstance().World().Register("Menu", new MenuScene());
	Engine::GetInstance().World().SetLoadScene("Menu");
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	if (Engine::GetInstance().Init("TestGame", 800, 608)) {
		InitGameplay();
		Engine::GetInstance().Start();
	}
	return 0;
}
