#pragma once
#include <string>
#include "IInput.h"

namespace buki {
	class Engine final {
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_input; }
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);

	private:
		IInput* m_input;
		bool m_IsRunning = false;
		bool m_IsInit = false;
	};
}