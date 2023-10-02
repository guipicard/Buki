#include "Component.h"

namespace buki 
{
	class Controller : public Component, public IUpdatable
	{
	public:
		Controller() : Controller(nullptr) {};
		Controller(Entity* _entity) { m_Entity = _entity; };
		virtual ~Controller() = default;

		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Destroy()  override;
	};
}
