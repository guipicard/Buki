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
	Point2D pos = m_Entity->GetPos();
	Graphics().DrawString(m_Text, m_Id, pos.x, pos.y, Color::White);
}

void buki::Text::SetPath(std::string path)
{
	m_Id = buki::Engine::GetInstance()->Graphics().LoadFont(path, 32);
	//buki::Engine::GetInstance()->Graphics().GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
}