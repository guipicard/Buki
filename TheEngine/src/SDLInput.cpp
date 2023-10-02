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
		/*case SDL_KEYUP:
			m_MyKeyboard[_event.key.keysym.scancode] = false;
			break;
		case SDL_KEYDOWN:
			m_MyKeyboard[_event.key.keysym.scancode] = true;
			break;*/
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button] = true;
			SDL_Log("Button down : %d)", _buttonDown.button);
			SDL_Log("at (%d, %d)", _buttonDown.x, _buttonDown.y);
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			m_MouseStates[_buttonUp.button] = false;
			Engine::GetInstance()->Log().LogMessage("Button up : " + std::to_string(_buttonUp.button));
			//SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);
			break;
		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			m_MouseX = _motion.x;
			m_MouseY = _motion.y;
			//SDL_Log("%d, %d", _motion.x, _motion.y);
			break;
			 
		}
	}
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}

bool SdlInput::IsKeyDown(int keycode)
{
	if (m_KeyStates[static_cast<int>(keycode)] == 1)
	{
		if (!m_MyKeyboard[static_cast<int>(keycode)])
		{
			m_MyKeyboard[static_cast<int>(keycode)] = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		m_MyKeyboard[static_cast<int>(keycode)] = false;
		return false;
	}
}

bool buki::SdlInput::IsKeyUp(int keycode)
{
	if (!m_KeyStates[static_cast<int>(keycode)] == 1)
	{
		if (m_MyKeyboard[static_cast<int>(keycode)])
		{
			m_MyKeyboard[static_cast<int>(keycode)] = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		m_MyKeyboard[static_cast<int>(keycode)] = false;
		return false;
	}
}

bool buki::SdlInput::IsKeyPressed(int keycode)
{
	return m_KeyStates[static_cast<int>(keycode)] == 1;
}

bool SdlInput::IsButtonDown(int button)
{
	return m_MouseStates[button];
}

void SdlInput::GetMousePosition(int* x, int* y)
{
	*x = m_MouseX;
	*y = m_MouseY;
}

