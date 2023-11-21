#include "SDLInput.h"
#include <SDL.h>
#include "Engine.h"

using namespace buki;

void SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event)) {
		switch (_event.type) {
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button - 1] = true;
			Engine::GetInstance().Log().LogMessage("Button up : " + std::to_string(_buttonDown.button));
			Engine::GetInstance().Log().LogMessage("at (%d, %d)" + std::to_string(_buttonDown.x) + std::to_string(_buttonDown.y));
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			m_MouseStates[_buttonUp.button - 1] = false;
			Engine::GetInstance().Log().LogMessage("Button up : " + std::to_string(_buttonUp.button));
			Engine::GetInstance().Log().LogMessage("at (%d, %d)" + std::to_string(_buttonUp.x) + std::to_string(_buttonUp.y));
			break;
		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			m_MouseX = _motion.x;
			m_MouseY = _motion.y;
			break;

		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
#if _DEBUG
	if (IsKeyDown(EKey::EKEY_ESCAPE))
	{
		SDL_Event quitEvent;
		quitEvent.type = SDL_QUIT;
		SDL_PushEvent(&quitEvent);
	}
#endif
}

bool buki::SdlInput::IsKeyPressed(EKey keycode)
{
	return m_KeyStates[static_cast<int>(keycode)] == 1;
}

bool SdlInput::IsKeyDown(EKey keycode)
{
	return m_KeyStates[static_cast<int>(keycode)] == 1 && !m_LateKeyStates[static_cast<int>(keycode)];
}

bool buki::SdlInput::IsKeyUp(EKey keycode)
{
	return m_KeyStates[static_cast<int>(keycode)] != 1 && m_LateKeyStates[static_cast<int>(keycode)];
}


bool SdlInput::IsButtonPressed(int button)
{
	return m_MouseStates[button];
}

bool buki::SdlInput::IsButtonDown(int button)
{
	return m_MouseStates[button] && !m_LateMouseStates[button];
}

bool buki::SdlInput::IsButtonUp(int button)
{
	return !m_MouseStates[button] && m_LateMouseStates[button];
}

void SdlInput::GetMousePosition(int* x, int* y)
{
	*x = m_MouseX;
	*y = m_MouseY;
}

void buki::SdlInput::ResetLateInputs()
{
	if (m_KeyStates != nullptr)
	{
		for (int i = 0; i < sizeof(m_LateKeyStates) / sizeof(m_LateKeyStates[0]); i++)
		{
			m_LateKeyStates[i] = m_KeyStates[i] == 1 ? true : false;
		}
	}
	for (int i = 0; i < sizeof(m_LateMouseStates) / sizeof(m_LateMouseStates[0]); i++)
	{
		m_LateMouseStates[i] = m_MouseStates[i] ? true : false;
	}
}
