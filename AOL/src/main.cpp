#define win32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#include "Engine.h"

void InitGameplay(void) {

}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT) {
	buki::Engine* theEngine = buki::Engine::GetInstance();
	if (theEngine->Init("TestGame", 800, 608)) {
		InitGameplay();
		theEngine->Start();
	}
	delete theEngine;
	return 0;
}
