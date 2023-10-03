#pragma once

enum class EKey {
	RIGHT = 79,
	LEFT = 80,
	DOWN = 81,
	UP = 82,
	RETURN = 40,
	ESCAPE = 41,
	BACKSPACE = 42,
	TAB = 43,
	SPACE = 44
};

namespace buki 
{
	class IInput
	{
	public:
		virtual ~IInput() = default;
		virtual bool IsKeyPressed(int key) = 0;
		virtual bool IsKeyDown(int key) = 0;
		virtual bool IsKeyUp(int key) = 0;
		virtual bool IsButtonPressed(int button) = 0;
		virtual bool IsButtonDown(int button) = 0;
		virtual bool IsButtonUp(int button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;
		virtual void ResetLateInputs() = 0;
	protected:
		friend class Engine;
		virtual void Update() = 0;
		bool m_IsRunning = true;
	};
}