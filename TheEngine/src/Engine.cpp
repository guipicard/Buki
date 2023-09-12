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

using namespace buki;

static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;

bool Engine::Init(const char* name, int w, int h)
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

	m_Graphics = new SDL_Graphics(_renderer);
	if (!m_Graphics)
	{
		m_Console->LogError(SDL_GetError());
		return false;
	}
	m_Console->LogSuccess("Graphics initialised");

	m_Square = new Square(20, 20, 100, 100, _renderer);
	m_Input = new SdlInput();

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
void Engine::ProcessInput(void)
{
	Input().Update();
}

static float speed = 50.0f;
void Engine::Update(float dt)
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

void Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	//SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	m_Graphics->Clear();
	m_Graphics->SetColor(Color::Red);
	//SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	RectF myRect{ 0.0f, 0.0f, 50.0f, 50.0f };
	m_Graphics->DrawRect(myRect, Color::Red);

	size_t text = m_Graphics->LoadTexture("./assets/pika.jpeg");
	RectI srcRect{ 0, 0, 0, 0 };
	m_Graphics->GetTextureSize(text, &srcRect.w, &srcRect.h);
	RectF dstRect{ 100.0f, 150.0f, srcRect.w, srcRect.h };
	Flip pikaFlip{false, false};
	m_Graphics->DrawTexture(text, srcRect, dstRect, 0, pikaFlip, Color::Black);
	m_Graphics->Present();
}

void Engine::Shutdown(void)
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
	if (m_Graphics != nullptr)
	{
		delete m_Graphics;
	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}
