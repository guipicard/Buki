#include <time.h>
#include "Engine.h"
#include <SDL.h>

static SDL_Renderer* _renderer = NULL;
static SDL_Window* _window = NULL;
bool buki::Engine::Init(const char* name, int w, int h) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log(SDL_GetError());
		return false;
	}

	int _x SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	Uint32 _flag = SDL_WINDOW_TOOLTIP;
	Uint32 _rendererFlag = SDL_RENDERER_ACCELERATED;

	_window = SDL_CreateWindow(name, _x, _y, w, h, _flag);
	if (!_window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, _rendererFlag);
	if (!_renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}
	m_IsInit = true;
	return true;
}

void buki::Engine::Start(void) {
	if (!m_IsInit) {
		if (!Init("Unknown title", 800, 600)) {
			return;
		}
	}

	const float MS_PER_FRAME = 16.0f; // 16 to get 60 fps
	m_IsRunning = true;
	float _end = clock();
	float _lag = 0.0f;
	float _elapsed = 0.0f;
	while (m_IsRunning) {
		const double _start = clock();
		_elapsed = (_start - _end);
		float _dt = _elapsed * 0.001f;
		_end = _start;
		_lag += _elapsed;
		ProcessInput();

		while (_lag >= MS_PER_FRAME)
		{
			Update(_dt);
			_lag -= MS_PER_FRAME;
		}
		float sleepTime = _start + MS_PER_FRAME - clock();
		if (sleepTime >= 0)
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
	SDL_Event _event;
	while (SDL_PollEvent(&_event)) {
		switch (_event.type) {
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		}
	}
	_keyStates = SDL_GetKeyboardState(nullptr);
}

static float x = 0.0f;
void buki::Engine::Update(float dt)
{
	if (_keyStates[SDL_SCANCODE_D]) {
		x += 10 * dt;
	}
}

void buki::Engine::Render(void)
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	SDL_Rect get_rect = { 0 };
	get_rect.x = x;
	get_rect.y = 100;
	get_rect.w = 100;
	get_rect.h = 100;
	SDL_RenderDrawRect(_renderer, &get_rect);

	SDL_RenderPresent(_renderer);
}

void buki::Engine::Shutdown(void)
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}
