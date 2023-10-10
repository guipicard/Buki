#pragma once
#include "Sprite.h"

namespace buki
{
	class Animation : public Sprite, public IUpdatable
	{
	public:
		Animation(Entity* _entity);
		void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
		void AddClip(const std::string& name, int start, int count, float delay);
		void Stop();
		void Play(const std::string& name, bool loop);
		void Draw();
		void Update(float dt);
	private:
		int m_FrameInRows = 0;
		int m_FrameWidth = 0;
		int m_FrameHeight = 0;
		int m_StartFrame = 0;
		int m_FrameCount = 0;
		float m_Delay = 0.0f;
		std::string m_Name = "";
	};
}