#pragma once
#include <string>
#include "IInput.h"
#include "IShape.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "Color.h"
#include "IWorld.h"

namespace buki {
	class Engine final {
	public:
		static Engine* GetInstance()
		{
			static Engine* instance;
			if (instance == nullptr)
			{
				instance = new Engine();
			}
			return instance;
		}
	private:
		Engine() {}

	public:
		Engine(Engine const&) = delete;
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
	public:
		IInput& Input() { return *m_Input; }
		IGraphics& Graphics() { return *m_Graphics; }
		IWorld& World() { return *m_World; }
		ILogger& Log() { return *m_Console; }
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);
	private:
		IInput* m_Input = nullptr;
		ILogger* m_Console = nullptr;
		IGraphics* m_Graphics = nullptr;
		IWorld* m_World = nullptr;
	private:
		bool m_IsInit = false;
	};
}
