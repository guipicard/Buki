#pragma once

#include "IAudio.h"
#include "SDL_mixer.h"
#include <map>

namespace buki
{
	class SDL_Audio : public IAudio
	{
	public:
		SDL_Audio();
		virtual ~SDL_Audio() override;
		virtual size_t LoadMusic(const std::string& filename) override;
		virtual size_t LoadSound(const std::string& filename) override;
		virtual void PlayMusic(size_t id) override;
		virtual void PlayMusic(size_t id, int loop) override;
		virtual void PlaySFX(size_t id) override;
		virtual void PlaySFX(size_t id, int loop) override;
		virtual void PauseMusic() override;
		virtual void StopMusic() override;
		virtual void ResumeMusic() override;
		virtual void SetVolume(int volume) override;
		virtual void SetVolume(size_t soundId, int volume) override;
		virtual void Destroy() override;
	private:
		std::map<size_t, Mix_Music*> &m_MusicCache = *new std::map<size_t, Mix_Music*>();
		std::map<size_t, Mix_Chunk*> &m_SfxCache = *new std::map<size_t, Mix_Chunk*>();
	};
}