#include "Sprite.h"
#include "Engine.h"

buki::Sprite::Sprite(Entity* _entity)
	: Component(_entity)
{
	m_Src = RectI();
	m_Dst = RectF();
	Point2D pos = m_Entity->GetPos();
	Point2D size = m_Entity->GetSize();

	m_Src.x = 0;
	m_Src.y = 0;
	m_Src.w = 0;
	m_Src.h = 0;

	m_Dst.w = size.x;
	m_Dst.h = size.y;
}

void buki::Sprite::Start()
{
}

void buki::Sprite::Draw()
{
	Point2D pos = m_Entity->GetPos();
	Point2D size = m_Entity->GetSize();
	m_Dst.x = pos.x;
	m_Dst.y = pos.y;
	const Flip& flip = Flip();
	Graphics().DrawTexture(m_Id, m_Src, m_Dst, 0.0, flip, Color::White);
}

void buki::Sprite::Destroy()
{
}

void buki::Sprite::SetPath(std::string path)
{
	m_Id = buki::Engine::GetInstance()->Graphics().LoadTexture(path);
	buki::Engine::GetInstance()->Graphics().GetTextureSize(m_Id, &m_Src.w, &m_Src.h);
}

void buki::Sprite::SetSrc(RectI _src)
{
	m_Src = _src;
}

void buki::Sprite::SetDst(RectF _dst)
{
	m_Dst = _dst;
}
