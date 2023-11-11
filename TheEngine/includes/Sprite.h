#pragma once

#include "Component.h"
#include "IGraphics.h"
#include <cstdlib>

struct RectF;
struct RectI;
namespace buki
{
	class Sprite : public Component, public IDrawable
	{
	public:
		Sprite(Entity* _entity);
		~Sprite() = default;
		virtual void Start() override;
		virtual void Draw() override;
		virtual void Destroy() override;
		virtual void SetPath(std::string path);
		void SetSrc(RectI _src);
		void SetDst(RectF _dst);
	protected:
		size_t m_Id = 0;
		RectI m_Src;
		RectF m_Dst;
	};
}
