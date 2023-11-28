#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"

buki::Sprite::Sprite(Entity* _entity)
	: Component(_entity)
{
}

void buki::Sprite::Draw()
{
	double _rot = m_Entity->GetRotation();
	Point2D pos, size;
	RectF _dst;
	m_Entity->GetRect(_dst);

	Graphics().DrawTexture(m_Id, m_Src, _dst, _rot, m_Flip, Color::WHITE);
}

void buki::Sprite::Load(const std::string& path)
{
	m_Id = Graphics().LoadTexture(path);
	Graphics().GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
}

void buki::Sprite::SetColor(const Color& color)
{
	m_Color.Set(color);
}

void buki::Sprite::SetFlip(bool h, bool v)
{
	m_Flip.h = h;
	m_Flip.v = v;
}
