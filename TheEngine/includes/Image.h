#include "Component.h"
#include <cstdlib>
#include <iostream>

namespace buki
{
	class Image : public Component, public IDrawable
	{
	public:
		Image() : Image(nullptr) {};
		Image(Entity* _entity) { m_Entity = _entity; };
		~Image() = default;
		virtual void Start() override;
		virtual void Draw() override;
		virtual void Destroy() override;
		void SetPath(std::string path);
	private:
		std::string m_AssetPath = "";
		size_t m_Id = 0;
	};
}