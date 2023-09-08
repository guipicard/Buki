#include <time.h>
#include "Engine.h"
#include <SDL.h>
#include<windows.h>
#include "SDLInput.h"
#include "Square.h"
#include "LogConsole.h"
#include "LogFile.h"

using namespace buki;

static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;

bool buki::Engine::Init(const char* name, int w, int h)
{
#if _DEBUG
	m_Console = new LogConsole();
#elif
	m_Console = new LogFile();
#endif
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		m_Console->LogError(SDL_GetError());
		return false;
	}
	m_Console->LogSuccess("SDL initialised");
	int _x SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_RESIZABLE;
	Uint32 _rendererFlag = SDL_RENDERER_ACCELERATED;

	_window = SDL_CreateWindow(name, _x, _y, w, h, _flag);
	if (!_window)
	{
		m_Console->LogError(SDL_GetError());
		return false;
	}
	m_Console->LogSuccess("Window initialised");
	_renderer = SDL_CreateRenderer(_window, -1, _rendererFlag);

	if (!_renderer)
	{
		m_Console->LogError(SDL_GetError());
		return false;
	}
	m_Console->LogSuccess("Renderer initialised");
	m_Square = new Square(20, 20, 100, 100, _renderer);
	m_Input = new SdlInput();

	m_IsInit = true;
	return true;
}

void buki::Engine::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 600)) {
			return;
		}
	}
	m_Console->LogSuccess("Buki initialised");
	const float MS_PER_FRAME = 16.0f; // 16 to get 60 fps
	m_Input->m_IsRunning = true;
	float _last = clock();
	float _elapsed = 0.0f;
	while (m_Input->m_IsRunning) {
		const double _new = clock();
		_elapsed = (_new - _last);
		float _dt = _elapsed * 0.001f;
		_last = _new;
		ProcessInput();
		Update(_dt);
		float sleepTime = clock() - (_new + MS_PER_FRAME);
		if (sleepTime > 0)
		{
			Sleep(sleepTime);
		}
		Render();
	}
	Shutdown();
}

static unsigned const char* _keyStates = NULL;
void buki::Engine::ProcessInput(void)
{
	Input().Update();
}

static float speed = 50.0f;
void buki::Engine::Update(float dt)
{
#if _DEBUG
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_ESCAPE)))
	{
		SDL_Event quitEvent;
		quitEvent.type = SDL_QUIT;

		// Push the SDL_QUIT event onto the event queue
		SDL_PushEvent(&quitEvent);
	}
#endif
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_RIGHT)))
	{
		float x = m_Square->GetPosX() + (50.0f * dt);
		float y = m_Square->GetPosY();
		m_Square->SetPosition(x, y);
	}
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_LEFT)))
	{
		float x = m_Square->GetPosX() - (50.0f * dt);
		float y = m_Square->GetPosY();
		m_Square->SetPosition(x, y);
	}
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_UP)))
	{
		float x = m_Square->GetPosX();
		float y = m_Square->GetPosY() - (50.0f * dt);
		m_Square->SetPosition(x, y);
	}
	if (m_Input->IsKeyDown(static_cast<int>(EKey::EKEY_DOWN)))
	{
		float x = m_Square->GetPosX();
		float y = m_Square->GetPosY() + (50.0f * dt);
		m_Square->SetPosition(x, y);
	}
}

void buki::Engine::Render(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	m_Square->Draw();

	SDL_RenderPresent(_renderer);
}

void buki::Engine::Shutdown(void)
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	if (m_Square != nullptr)
	{
		delete m_Square;
	}
	if (m_Console != nullptr)
	{
		delete m_Console;
	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}
