#pragma once
#include <Sprite.h>
#include <map>
#include <string>
#include <IUpdatable.h>
#include <RectI.h>
#include <RectF.h>

namespace buki
{
	class Entity;
	struct AnimationClip
	{
		int startX;
		int startY;
		int count;
		float delay;
	};

	class Animation : public Sprite, public IUpdatable
	{
	public:
		virtual ~Animation() = default;
		Animation(Entity* _entity);
		virtual void Update(float dt) override;
		void Init(int start, int frameWidth, int frameHeight);
		void AddClip(const std::string& name, int startX, int startY, int count, float delay);
		void Stop();
		void Play(const std::string& name, bool loop);
		bool IsStopped() { return !m_Playing; }
	private:
		void UpdateFrame();

		std::map<std::string, AnimationClip> m_Clips;

		int m_FrameWidth = 0;
		int m_FrameHeight = 0;
		int m_FirstFrame = 0;
		int m_LastFrame = 0;
		float m_Delay = 0.0f;
		float m_Elapsed = 0.0f;
		bool m_Playing = false;
		bool m_Loop = false;
		int m_CurrentFrame = 0;
		std::string m_CurrentClip;

		int m_AnimDir = 1;
	};
}