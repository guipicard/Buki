#pragma once
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IWorld.h"
#include "IAudio.h"
#include "ICollision.h"

namespace buki {
	class Engine final {
	public:
		static Engine& GetInstance()
		{
			static Engine instance;
			return instance;
		}

		bool Init(const std::string& title, int w, int h);
		void Start(void);

	private:
		Engine() = default;

		void ProcessInput(void);
		void Update(float dt);
		void Render(void);
		void Shutdown(void);
		
	public:
		IInput& Input() const { return *m_Input; }
		ILogger& Log() const { return *m_Console; }
		IGraphics& Graphics() const { return *m_Graphics; }
		IAudio& Audio() const { return *m_Audio; }
		IWorld& World() const { return *m_World; }
		ICollision& Collision() const { return *m_Collision; }
		
	private:
		bool m_IsInit = false;

		IInput* m_Input = nullptr;
		ILogger* m_Console = nullptr;
		IGraphics* m_Graphics = nullptr;
		IWorld* m_World = nullptr;
		IAudio* m_Audio = nullptr;
		ICollision* m_Collision = nullptr;
	};
}
