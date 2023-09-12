#pragma once
#include <string>
#include "IInput.h"
#include "IShape.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "Color.h"

namespace buki {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_Input; }
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);

	private:
		IInput* m_Input = nullptr;
		IShape* m_Square = nullptr;
		ILogger* m_Console = nullptr;
		IGraphics* m_Graphics = nullptr;
		//bool m_IsRunning = false;
		bool m_IsInit = false;
	};
}