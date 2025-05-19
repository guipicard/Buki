#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"
#include "Observer.h"
#include "BaseScene.h"
#include "Subject.h"
#include "Color.h"
#include <string>

namespace buki
{
	struct Text;
	struct Entity;
	struct Sprite;
	struct Button : public Component, public IUpdatable, public IDrawable
	{
		Button(Entity* entity);
		virtual void Start() override;
		virtual void Update(float dt) override;
		virtual void Draw(float alpha) override;
		Text* GetText() const { return textContainer; }
		Vector2 GetPosition() const;
		//Vector2 GetFullPosition() const;
		Vector2 GetSize() const;
		//void SetSize(const Vector2 _size);
		//Vector2 GetFullSize() const;
		void SetImage(const std::string _path);
		//void SetPosition(const Vector2 _pos) { position = _pos; }
		void SetbuttonFont(const std::string font) { textFont = font; }
		void SetButtonText(const std::string text, int size);
		void SetMessage(std::string _message) { message = _message; }
		void ShowBackground(bool _state) { background = _state; }
		inline void SetOutlineColor(Color _color) { outlineColor = _color; }
		inline void SetFitToText(bool _state) { sizeFitToText = _state; }
		Subject<std::string> OnClick;
	private:
		bool m_Draw = false;
		std::string buttonText;
		std::string textFont;
		std::string message;
		Sprite* buttonSprite;
		Text* textContainer;
		int textSize;
		bool clicked;
		bool background = true;
		Color outlineColor;
		bool sizeFitToText = true;
	};
}
