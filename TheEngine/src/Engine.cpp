#include <time.h>
#include "Engine.h"
#include <SDL.h>
#include<windows.h>
#include "SDLInput.h"
#include "Square.h"
#include "LogConsole.h"
#include "LogFile.h"
#include <SDL_image.h>
#include "SDL_Graphics.h"
#include "Color.cpp"
#include "WorldService.h"
#include "Square.h"
#include "DemoScene.h"
#include "SDL_Audio.h"
//#include <vld.h>

using namespace buki;

bool Engine::Init(const char* name, int w, int h)
{
#if _DEBUG
	m_Console = new LogConsole();
#else
	m_Console = new LogFile();
#endif
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		m_Console->LogError(SDL_GetError());
		return false;
	}
	m_Console->LogSuccess("SDL initialised");

	m_Graphics = new SDL_Graphics();
	if (!m_Graphics)
	{
		m_Console->LogError(SDL_GetError());
		return false;
	}
	if (!m_Graphics->Initialize(name, w, h))
	{
		return false;
	}
	m_Console->LogSuccess("Graphics initialised");

	m_Input = new SdlInput();
	m_World = new WorldService();
	m_Audio = new SDL_Audio();

	m_World->Register("Demo", new DemoScene());
	m_World->Load("Demo");
	
	mumu = m_Audio->LoadMusic("./audio/mixkit-driving-ambition-32.mp3");
	sam = m_Audio->LoadSound("./audio/mixkit-arcade-retro-game-over-213.wav");

	m_IsInit = true;
	return m_IsInit;
}

void Engine::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 600)) {
			return;
		}
	}
	m_Console->LogSuccess("Buki initialised");

	Audio().PlayMusic(mumu);

	const float MS_PER_FRAME = 16.0f; // 16 to get 60 fps
	Input().m_IsRunning = true;
	float _last = static_cast<float>(clock());
	//float _lag = 0.0f;
	float _elapsed = 0.0f;
	while (Input().m_IsRunning) {
		const double _new = clock();
		_elapsed = (static_cast<float>(_new) - _last);
		float _dt = _elapsed * 0.001f;
		_last = static_cast<float>(_new);
		//_lag += _elapsed;
		ProcessInput();
		Update(_dt);
		/*while (_lag >= MS_PER_FRAME)
		{
			Update(_dt);
			_lag -= MS_PER_FRAME;
		}*/
		Input().ResetLateInputs();
		float sleepTime = static_cast<float>(_new) + MS_PER_FRAME - static_cast<float>(clock());
		if (sleepTime >= 0)
		{
			Sleep(static_cast<DWORD>(sleepTime));
		}
		Render();
	}
	Shutdown();
}

void Engine::ProcessInput(void)
{
	Input().Update();
}

void Engine::Update(float dt)
{
#if _DEBUG
	if (Input().IsKeyDown(EKey::ESCAPE))
	{
		SDL_Event quitEvent;
		quitEvent.type = SDL_QUIT;

		// Push the SDL_QUIT event onto the event queue
		SDL_PushEvent(&quitEvent);
	}
#endif
	m_World->Update(dt);
	if (Input().IsKeyDown(EKey::RETURN))
	{
		Audio().PlaySFX(sam);
	}
}

void Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();

	m_World->Render();

	m_Graphics->Present();

}

void Engine::Shutdown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	if (m_Console != nullptr)
	{
		delete m_Console;
	}
	if (m_Graphics != nullptr)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
	}
	if (m_Audio != nullptr)
	{
		m_Audio->Destroy();
		delete m_Audio;
	}
	if (m_World != nullptr)
	{
		m_World->Destroy();
		delete m_World;
	}
}
