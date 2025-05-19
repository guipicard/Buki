#pragma once

#include <Sprite.h>
#include <IDrawable.h>
#include <Color.h>
#include <string>

namespace buki
{
	struct Text : public Sprite
	{
		Text(Entity* _entity);
		~Text();
		void Draw(float alpha);
		void LoadText(const std::string& path, int size);
		void SetText(std::string _text);
		inline void SetBackground(const bool _state) { m_Background = _state; }
		inline Vector2 GetSize() { return textSize; }
		//inline void GetSize(Vector2 _pos) { textPos = _pos; }
		inline void SetBackgroundColor(Color _color) { backgroundColor = _color; }
	private:
		std::string m_Text = "";
		bool m_Background = false;
		Vector2 textSize;
		//Vector2 textPos;
		Color backgroundColor;
	};
}
