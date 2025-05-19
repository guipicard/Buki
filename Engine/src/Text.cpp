#include "Engine.h"
#include "Text.h"
#include "Entity.h"

buki::Text::Text(Entity* _entity)
	: Sprite(_entity)
{
	backgroundColor = Color::BLACK;
	//textPos = Vector2();
}

buki::Text::~Text()
{
}

void buki::Text::Draw(float alpha)
{
	Vector2 pos, size;
	pos = m_Entity->GetTransform()->GetPosition() + m_Position;
	size = m_Entity->GetTransform()->GetSize() + textSize;
	if (m_Background)
	{
		Engine::GetInstance().Graphics().FillRect(RectF{ pos.x, pos.y, m_Size.x*1.5f , m_Size.y*1.5f }, backgroundColor);
	}
	Graphics().DrawString(m_Text, m_Id, pos.x, pos.y, m_Color);
}

void buki::Text::SetText(std::string _text)
{
	m_Text = _text;
	float w, h;
	Graphics().GetTextSize(m_Text, m_Id, &w, &h);
	textSize = Vector2(w, h);
}

void buki::Text::LoadText(const std::string& path, int size)
{
	m_Id = Graphics().LoadFont(path, size);
}
