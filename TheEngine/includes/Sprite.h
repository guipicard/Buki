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
		void SetPath(std::string path);
		void SetSrc(RectI _src);
		void SetDst(RectF _dst);
	protected:
		size_t m_Id = 0;
		RectI m_Src;
		RectF m_Dst;
	};

	/*template<typename T>
	inline T* Sprite::SetPath(std::string path)
	{
		m_AssetPath = path;
		m_Id = buki::Engine::GetInstance()->Graphics().LoadTexture(m_AssetPath);
		buki::Engine::GetInstance()->Graphics().GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
		return this;
	}

	template<typename T>
	inline T* Sprite::SetSrc(RectI _src)
	{
		m_Src = _src;
		return this;
	}

	template<typename T>
	inline T* Sprite::SetDst(RectF _dst)
	{
		m_Dst = _dst;
		return this;
	}*/
}
