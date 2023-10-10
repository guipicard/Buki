#include "Animation.h"

buki::Animation::Animation(Entity* _entity)
	: Sprite(_entity)
{

}

void buki::Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	m_FrameInRows = frameInRows;
	m_FrameWidth = frameWidth;
	m_FrameHeight = frameHeight;
}

void buki::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	m_Name = name;
	m_StartFrame = start;
	m_FrameCount = count;
	m_Delay = delay;
}

void buki::Animation::Stop()
{
}

void buki::Animation::Play(const std::string& name, bool loop)
{
}

void buki::Animation::Draw()
{
}

void buki::Animation::Update(float dt)
{

}
