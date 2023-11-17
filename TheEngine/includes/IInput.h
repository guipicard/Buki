#pragma once
#include <EKey.h>

namespace buki 
{
	class IInput
	{
	public:
		virtual ~IInput() = default;
		virtual bool IsKeyPressed(EKey key) = 0;
		virtual bool IsKeyDown(EKey key) = 0;
		virtual bool IsKeyUp(EKey key) = 0;
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