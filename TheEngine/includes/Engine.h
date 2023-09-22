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
		// pris sur post stackoverflow https://stackoverflow.com/questions/1008019/how-do-you-implement-the-singleton-design-pattern
	private:
		Engine() {}

	public:
		Engine(Engine const&) = delete;
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_Input; }
		IGraphics& Graphics() { return *m_Graphics; }
		IWorld& World() { return *m_World; }
	private:
		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);

	private:
		IInput* m_Input = nullptr;
		ILogger* m_Console = nullptr;
		IGraphics* m_Graphics = nullptr;
		bool m_IsInit = false;

		IWorld* m_World = nullptr;
		Entity* m_Entity1 = nullptr;
		Entity* m_Entity2 = nullptr;
	};
}