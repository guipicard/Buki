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
		static Engine& GetInstance() 
		{
			static Engine instance;
			return instance;
		}

	private:
		Engine() {}                    // Constructor? (the {} brackets) are needed here.

		// C++ 03
		// ========
		// Don't forget to declare these two. You want to make sure they
		// are inaccessible(especially from outside), otherwise, you may accidentally get copies of
		// your singleton appearing.
		//Engine(Engine const&);              // Don't Implement
		//void operator=(Engine const&); // Don't implement

		// C++ 11
		// =======
		// We can use the better technique of deleting the methods
		// we don't want.
	public:
		Engine(Engine const&) = delete;
		void operator=(Engine const&) = delete;

		// Note: Scott Meyers mentions in his Effective Modern
		//       C++ book, that deleted functions should generally
		//       be public as it results in better error messages
		//       due to the compilers behavior to check accessibility
		//       before deleted status
	public:
		bool Init(const char* name, int w, int h);
		void Start(void);
		IInput& Input() { return *m_Input; }
		IGraphics& Graphics() { return *m_Graphics; }
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