#define win32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"
#include "ShapesDemo.h"
#include "AngryBirdDemo.h"
#include "MenuScene.h"
#include "Platformer.h"
#include "AGLevel1.h"
#include <string>

using namespace buki;

void InitGameplay(void) {
	Engine::GetInstance().World().Register("Shapes", new ShapesDemo());
	Engine::GetInstance().World().Register("AngryBird", new AngryBirdDemo());
	Engine::GetInstance().World().Register("Menu", new MenuScene());
	Engine::GetInstance().World().Register("Platformer", new Platformer());

	Engine::GetInstance().World().Register("Ag_Lvl_1", new AGLevel1());
	
	Engine::GetInstance().World().SetLoadScene("Menu");
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {{}
	if (Engine::GetInstance().Init("Buki Engine", 1920, 1080)) {
		InitGameplay();
		Engine::GetInstance().Start();
	}
	return 0;
}
