#pragma once
#include "Button.h"
#include "IInput.h"
#include "ICollision.h"
#include "Vector2.h"
#include "Entity.h"
#include "IWorld.h"
#include "IGraphics.h"
#include "ILogger.h"
#include "Text.h"
#include <string>

buki::Button::Button(Entity* entity)
	: Component(entity)
{
	buttonSprite = m_Entity->AddComponent<Sprite>();
	textContainer = m_Entity->AddComponent<Text>();
	textSize = 12;
	textFont = "./fonts/Kenney/Kenney-Bold-modified.ttf";
	buttonText = "Button Text";
	m_Draw = false;
	clicked = false;
	outlineColor = Color::WHITE;
}

void buki::Button::Start()
{

}

void buki::Button::Update(float dt)
{
	float mouseX, mouseY;
	Vector2 pos, size;
	Input().GetMousePosition(&mouseX, &mouseY);
	pos = GetPosition();
	size = GetSize();
	if (sizeFitToText) size += textContainer->GetSize();
	
	if (Collision().CheckPointRect(mouseX, mouseY, pos.x, pos.y, size.x, size.y))
	{
		m_Draw = true;
		if (Input().IsButtonDown(0))
		{
			if (!clicked) OnClick.Invoke(message);
			clicked = true;
		}
	}
	else
	{
		m_Draw = false;
	}
	if (clicked)
	{
		if (Input().IsButtonUp(0))
		{
			clicked = false;
		}
	}
}

void buki::Button::Draw(float alpha)
{
	//Vector2 pos = GetFullPosition();
	Vector2 pos = GetPosition();
	Vector2 size = GetSize();
	if (sizeFitToText) size += textContainer->GetSize();
	if (buttonSprite->GetPath() == "")
	{
		//if (background) Graphics().FillRect(pos.x, pos.y, currentSize.x, currentSize.y, Color::BLACK);
		if (m_Draw) Graphics().DrawRect(pos.x, pos.y, size.x, size.y, outlineColor);
	}
}

buki::Vector2 buki::Button::GetPosition() const
{
	return m_Entity->GetTransform()->GetPosition();
}

//buki::Vector2 buki::Button::GetFullPosition() const
//{
//	return m_Entity->GetTransform()->GetPosition() + textContainer->GetPosition() + position;
//}
//
//void buki::Button::SetSize(const Vector2 _size)
//{
//	size = _size;
//	fullSize = GetFullSize();
//	zoomedSize = fullSize + Vector2(0.2f, 0.2f);
//	currentSize = fullSize;
//}
//
//buki::Vector2 buki::Button::GetFullSize() const
//{
//	return m_Entity->GetTransform()->GetSize() + textContainer->GetSize() + size;
//}

buki::Vector2 buki::Button::GetSize() const
{
	return m_Entity->GetTransform()->GetSize();
}

void buki::Button::SetImage(const std::string _path)
{
	buttonSprite->Load(_path);
	buttonSprite->SetSize(GetSize());
}

void buki::Button::SetButtonText(const std::string text, const int s)
{
	textSize = s;
	buttonText = text;
	textContainer->LoadText(textFont, textSize);
	textContainer->SetText(buttonText);
	m_Entity->GetTransform()->SetSize(m_Entity->GetTransform()->GetSize());
}
