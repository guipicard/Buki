#pragma once
#include "IInput.h"
#include "ILogger.h"
#include "IGraphics.h"
#include "IWorld.h"
#include "IAudio.h"
#include "ICollision.h"
#include "IPhysics.h"

namespace buki {
	typedef uint32_t Uint32;
	struct Engine final {
		static Engine& GetInstance()
		{
			static Engine instance;
			return instance;
		}

		bool Init(const std::string& title, int w, int h);
		void Start(void);
		inline int GetFps() const { return m_CurrentFPS; }
		inline int GetPps() const { return m_CurrentPPS; }
	private:
		Engine() = default;

		void ProcessInput(void) const;
		void FixedUpdate(float dt);
		void Update(float dt);
		void Render(float alpha);
		void Shutdown(void);
		
	public:
		inline IInput& Input() const { return *m_Input; }
		inline ILogger& Log() const { return *m_Console; }
		inline IGraphics& Graphics() const { return *m_Graphics; }
		inline IAudio& Audio() const { return *m_Audio; }
		inline IWorld& World() const { return *m_World; }
		inline ICollision& Collision() const { return *m_Collision; }
		inline IPhysics& Physics() const { return *m_Physics; }
		
	private:
		bool m_IsInit = false;
		const Uint32 TARGET_FPS = 160;
		const Uint32 MS_PER_FRAME = 1000 / TARGET_FPS;

		const Uint32 TARGET_PPS = 60;
		const Uint32 FIXED_TIMESTEP = 1000 / TARGET_PPS;
		
		int m_CurrentFPS = 0;
		int m_CurrentPPS = 0;

		IInput* m_Input = nullptr;
		ILogger* m_Console = nullptr;
		IGraphics* m_Graphics = nullptr;
		IWorld* m_World = nullptr;
		IAudio* m_Audio = nullptr;
		ICollision* m_Collision = nullptr;
		IPhysics* m_Physics = nullptr;
	};
}
