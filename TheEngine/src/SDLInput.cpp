#include "SDLInput.h"
#include <SDL.h>

namespace buki {

	void SdlInput::Update()
	{
		SDL_Event _event;
		while (SDL_PollEvent(&_event)) {
			switch (_event.type) {
			case SDL_QUIT:
				break;
			}
		}
		m_KeyStates = SDL_GetKeyboardState(nullptr);
	}

	bool SdlInput::IsKeyDown(int keycode)
	{
		return false;
	}

	bool SdlInput::IsButtonDown(int button)
	{
		return false;
	}

	void SdlInput::GetMousePosition(int* x, int* y)
	{
	}

}