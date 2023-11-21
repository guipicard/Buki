#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <Flip.h>
#include <RectI.h>
#include <string>

namespace buki
{
	class Sprite : public Component, public IDrawable
	{
	public:
		virtual ~Sprite() = default;
		Sprite(Entity* _entity);

		virtual void Draw() override;
		virtual void Load(const std::string& path);

		void SetColor(const Color& color);
		void SetFlip(bool h, bool v);
		bool GetFlipH() const { return m_Flip.h; }
		bool GetFlipV() const { return m_Flip.v; }

	private:
		size_t m_Id = 0;
		Color m_Color = Color::WHITE;
		Flip m_Flip = Flip();

	protected:
		RectI m_Src = RectI();
	};
}
