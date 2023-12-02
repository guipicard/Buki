#include "Text.h"
#include "Engine.h"

buki::Text::Text(Entity* _entity)
	: Sprite(_entity)
{
}

buki::Text::~Text()
{
}

void buki::Text::Draw()
{
	Point2D pos;
	m_Entity->GetPosition(pos);
	Graphics().DrawString(m_Text, m_Id, pos.x, pos.y, Color::WHITE);
}

void buki::Text::SetText(std::string _text)
{
	m_Text = _text;
	Graphics().GetTextSize(m_Text, m_Id, &m_W, &m_H);
	m_Entity->SetSize(Point2D(m_W, m_H));
}

void buki::Text::LoadText(const std::string& path, int size)
{
	m_Id = Graphics().LoadFont(path, size);
}
