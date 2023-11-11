#pragma once
#include "Component.h"

typedef std::pair<float, std::vector<RectI>> TFrameset;
typedef std::map<std::string, TFrameset> TFramemap;

namespace buki
{
	class Animation : public Component, public IDrawable, public IUpdatable
	{
	public:
		virtual ~Animation() {}
		Animation(Entity* _entity);
		void SetPath(std::string path);
		void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
		void AddClip(const std::string& name, int start, int count, int row, float delay);
		void Stop();
		void Play(const std::string& name, bool loop);
		virtual void Draw() override;
		virtual void Update(float dt) override;
		void SetFlip(bool x, bool y) { m_Flip = Flip(x, y); }
		bool IsStopped() { return !m_Play; }
	private:
		TFrameset m_Frameset;
		TFramemap m_Framemap;
		int m_FrameInRows = 0;
		int m_FrameWidth = 0;
		int m_FrameHeight = 0;
		int m_StartFrame = 0;
		int m_FrameCount = 0;
		int m_FramesRow = 0;
		float m_Delay = 0.0f;
	private:
		size_t m_Id;
		bool m_Loop;
		bool m_Play;
		Flip m_Flip;
		int m_CurrentFrame;
		float m_Time = 0.0f;
		int m_NextFrame = 0;
	};
}