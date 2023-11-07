#define win32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"
#include "DemoScene.h"

using namespace buki;

Engine* theEngine = Engine::GetInstance();

void InitGameplay(void) {
	theEngine->World().Register("Demo", new DemoScene());
	theEngine->World().Load("Demo");
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	if (theEngine->Init("TestGame", 800, 608)) {
		InitGameplay();
		theEngine->Start();
	}
	delete theEngine;
	return 0;
}
