#pragma once
#include "IInput.h"

enum class EKey {
	EKEY_RIGHT = 79,
	EKEY_LEFT = 80,
	EKEY_DOWN = 81,
	EKEY_UP = 82,
	EKEY_RETURN = 40,
	EKEY_ESCAPE = 41,
	EKEY_BACKSPACE = 42,
	EKEY_TAB = 43,
	EKEY_SPACE = 44
};

namespace buki {

	class SdlInput final : public IInput
	{
	public:
		virtual ~SdlInput() = default;
		virtual void Update() override;
		virtual bool IsKeyDown(int keycode) override;
		virtual bool IsButtonDown(int button) override;
		virtual void GetMousePosition(int* x, int* y) override;
	private:
		const unsigned char* m_KeyStates = nullptr;
		int m_MouseX = 0;
		int m_MouseY = 0;
		bool m_MouseStates[3]{ false, false, false };
	};
}
