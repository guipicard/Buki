#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"

buki::Sprite::Sprite(Entity* _entity)
	: Component(_entity)
{
	m_Size = m_Entity->GetTransform()->GetSize();
}

void buki::Sprite::Draw(float alpha)
{
	Transform* state = m_Entity->GetTransform();
	RectF _dst(
		(state->GetPosition().x + m_Position.x - (m_Size.x * 0.5f)),
		(state->GetPosition().y + m_Position.y - (m_Size.y * 0.5f)),
		m_Size.x,
		m_Size.y
	);
	/*if (m_LastDst == RectF())
	{
		m_LastDst = _dst;
	}
	RectF dest = m_LastDst + ((_dst - m_LastDst) * alpha);*/
	//dest.w = m_Size.x;
	//dest.h = m_Size.y;
	//m_LastDst = _dst;
	Graphics().DrawTexture(m_Id, m_Src, _dst, state->GetRotation().GetRadians(), m_Flip, m_Color);
}

void buki::Sprite::Load(const std::string& _path)
{
	path = _path;
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
