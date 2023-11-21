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
	m_Entity->GetPosition(&pos);
	Graphics().DrawString(m_Text, m_Id, pos.x, pos.y, Color::WHITE);
}

void buki::Text::Load(const std::string& path)
{
	m_Id = Graphics().LoadFont(path, 32);
	//buki::Engine::GetInstance()->Graphics().GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
}
