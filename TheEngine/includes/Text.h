#pragma once

#include <Sprite.h>
#include <IDrawable.h>
#include <Color.h>
#include <string>

namespace buki
{
	class Text : public Sprite
	{
	public:
		Text(Entity* _entity);
		~Text();
		void Draw();
		void LoadText(const std::string& path, int size);
		void SetText(std::string _text);
		size_t GetId() const { return m_Id; }
		int GetW() { return m_W; }
		int GetH() { return m_H; }
	private:
		std::string m_Text = "";
		size_t m_Id = 0;
		int m_W = 0;
		int m_H = 0;
	};
}