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
//#include <vld.h>

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

	m_Entity1 = new Square("first", 50, 50, 50, 50, Color::Red);

	m_Entity2 = new Square("second", 100, 100, 100, 100, Color::Blue);

	m_World->Add(m_Entity1);
	m_World->Add(m_Entity2);

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

	Point2D pos1 = m_Entity1->GetPos();
	Point2D pos2 = m_Entity2->GetPos();
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::RIGHT)))
	{
		pos1.x += 10 * dt;
		pos2.x -= 10 * dt;
	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::LEFT)))
	{
		pos1.x -= 10 * dt;
		pos2.x += 10 * dt;
	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::UP)))
	{
		pos1.y -= 10 * dt;
		pos2.y += 10 * dt;
	}
	if (buki::Engine::GetInstance().Input().IsKeyDown(static_cast<int>(EKey::DOWN)))
	{
		pos1.y += 10 * dt;
		pos2.y -= 10 * dt;
	}
	m_Entity1->SetPos(pos1);
	m_Entity2->SetPos(pos2);
}

void Engine::Render(void)
{
	m_Graphics->SetColor(Color::Black);
	m_Graphics->Clear();

	/*m_Graphics->SetColor(Color::Red);
	RectF myRect{ 0.0f, 0.0f, 50.0f, 50.0f };
	m_Graphics->DrawRect(myRect, Color::Red);

	size_t texture = m_Graphics->LoadTexture("./assets/pika.jpeg");
	RectI srcRect{ 0, 0, 0, 0 };
	m_Graphics->GetTextureSize(texture, &srcRect.w, &srcRect.h);
	RectF dstRect{ 100.0f, 150.0f, srcRect.w, srcRect.h };
	Flip pikaFlip{ false, false };
	m_Graphics->DrawTexture(texture, srcRect, dstRect, 0, pikaFlip, Color::Black);*/

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
	if (m_World != nullptr)
	{
		m_World->Destroy();
		delete m_World;
	}
}
