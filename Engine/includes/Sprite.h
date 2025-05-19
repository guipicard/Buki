#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <BukiContainers.h>
#include <Color.h>
#include <Flip.h>
#include <RectI.h>
#include <RectF.h>
#include <string>
#include <vector>

namespace buki
{
	struct Sprite : public Component, public IDrawable
	{
		virtual ~Sprite() = default;
		Sprite(Entity* _entity);

		virtual void Draw(float alpha) override;
		virtual void Load(const std::string& _path);

		bool GetFlipH() const { return m_Flip.h; }
		bool GetFlipV() const { return m_Flip.v; }
		void SetColor(const Color& color);
		void SetFlip(bool h, bool v);

		inline Vector2 GetPosition() const { return m_Position; }
		inline Vector2 GetSize() const { return m_Size; }
		inline int GetW() const { return static_cast<int>(m_Size.x); }
		inline int GetH() const { return static_cast<int>(m_Size.y); }
		virtual inline void SetPosition(Vector2 _position) { m_Position = _position; }
		inline void SetSize(Vector2 _size) { m_Size = _size; }
		inline std::string GetPath() { return path; }
	private:
		Flip m_Flip = Flip();
	protected:
		std::string path;
		Color m_Color = Color::WHITE;
		Vector2 m_Position = Vector2();
		size_t m_Id = 0;
		RectI m_Src = RectI();
		Vector2 m_Size = Vector2();
		RectF m_LastDst = RectF();
	};
}
