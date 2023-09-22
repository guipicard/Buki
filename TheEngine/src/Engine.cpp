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
#include <vld.h>
#include "DemoScene.h"

using namespace buki;

//static const Engine& theEngine;

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
	m_World->Register("Menu", new DemoScene());
	m_World->Register("NotMenu", new DemoScene());
	m_World->Load("Menu");

	m_IsInit = true;
	return true;
}

void Engine::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 600)) {
			return;
		}
	}
	m_Console->LogSuccess("Buki initialised");
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
		float sleepTime = static_cast<float>(_new) + MS_PER_FRAME - static_cast<float>(clock());
		if (sleepTime >= 0)
		{
			Sleep(static_cast<DWORD>(sleepTime));
		}
		Render();
	}
	Shutdown();
}

static unsigned const char* _keyStates = NULL;
void Engine::ProcessInput(void)
{
	Input().Update();
}

void Engine::Update(float dt)
{
#if _DEBUG
	if (Input().IsKeyDown(static_cast<int>(EKey::ESCAPE)))
	{
		SDL_Event quitEvent;
		quitEvent.type = SDL_QUIT;

		// Push the SDL_QUIT event onto the event queue
		SDL_PushEvent(&quitEvent);
	}
#endif
	m_World->Update(dt);
	if (Input().IsKeyDown(static_cast<int>(EKey::SPACE)))
	{
		World().Load("NotMenu");
	}
	
}

void Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();

	m_World->Render();

	/*size_t id = Graphics().LoadTexture("./assets/pika.jpeg");
	Graphics().DrawTexture(id, Color::White);*/

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
	if (m_World != nullptr)
	{
		m_World->Destroy();
		delete m_World;
	}
}
