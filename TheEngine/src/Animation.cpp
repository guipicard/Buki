#include "Animation.h"

buki::Animation::Animation(Entity* _entity)
	: Component(_entity)
{
	m_Id = 0;
	m_CurrentFrame = 0;
	m_Loop = false;
	m_Play = false;
	m_Flip = Flip();
}

void buki::Animation::SetPath(std::string path)
{
	m_Id = Graphics().LoadTexture(path);
}

void buki::Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	m_FrameInRows = frameInRows;
	m_FrameWidth = frameWidth;
	m_FrameHeight = frameHeight;
}

void buki::Animation::AddClip(const std::string& name, int start, int count, int row, float delay)
{
	m_StartFrame = start;
	m_FrameCount = count;
	m_FramesRow = row;
	m_Delay = delay;
	TFrameset newFrameset;
	newFrameset.first = delay;
	const int _y = m_FramesRow;
	for (int i = start; i < start + count; i++)
	{
		const int _x = i;
		RectI _tile(
			_x * m_FrameWidth,
			_y * m_FrameHeight,
			m_FrameWidth,
			m_FrameHeight);
		newFrameset.second.push_back(_tile);
	}
	m_Framemap.emplace(name, newFrameset);
	m_Frameset = newFrameset;
}

void buki::Animation::Stop()
{
	m_Play = false;
}

void buki::Animation::Play(const std::string& name, bool loop)
{
	m_NextFrame = 1;
	m_Loop = loop;
	m_Play = true;
	m_CurrentFrame = 0;
	m_Time = 0.0f;
	m_Frameset = m_Framemap[name];
}

void buki::Animation::Draw()
{
	float x = m_Entity->GetPos().x;
	float y = m_Entity->GetPos().y;
	float w = m_Entity->GetSize().x;
	float h = m_Entity->GetSize().y;
	RectF _dst{
					x,
					y,
					w,
					h
	};
	Graphics().DrawTexture(m_Id, m_Frameset.second[m_CurrentFrame], _dst, 0.0, m_Flip, Color::White);
}

void buki::Animation::Update(float dt)
{
	m_Time += dt;
	if (m_Play)
	{
		if (m_Time > m_Frameset.first)
		{
			m_CurrentFrame += m_NextFrame;
			if (m_Loop)
			{
				if (m_CurrentFrame == m_Frameset.second.size() - 1 || m_CurrentFrame == 0)
				{
					m_NextFrame *= -1;
				}
			}
			else
			{
				if (m_CurrentFrame == m_Frameset.second.size() - 1)
				{
					Stop();
				}

			}
			m_Time = 0.0f;
		}
	}
}
