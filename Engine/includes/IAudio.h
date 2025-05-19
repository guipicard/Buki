#pragma once
#include <cstdlib>
#include <string>

namespace buki
{
    struct IAudio
    {
        virtual ~IAudio() = default; // Destructeur virtuel par d�faut.

        // Charge un fichier de musique et retourne un identifiant pour r�f�rencer la musique.
        virtual size_t LoadMusic(const std::string& filename) = 0;

        // Charge un fichier de son (effet sonore) et retourne un identifiant pour le r�f�rencer.
        virtual size_t LoadSound(const std::string& filename) = 0;

        // Joue la musique r�f�renc�e par l'identifiant id.
        virtual void PlayMusic(size_t id) = 0;

        // Joue la musique r�f�renc�e par l'identifiant id, avec une option pour r�p�ter la musique un certain nombre de fois.
        virtual void PlayMusic(size_t id, int loop) = 0;

        // Joue un effet sonore (SFX) r�f�renc� par l'identifiant id.
        virtual void PlaySFX(size_t id) = 0;

        // Joue un effet sonore (SFX) r�f�renc� par l'identifiant id, avec une option pour le r�p�ter un certain nombre de fois.
        virtual void PlaySFX(size_t id, int loop) = 0;

        // Met en pause la musique actuellement jou�e.
        virtual void PauseMusic() = 0;

        // Arr�te la musique actuellement jou�e.
        virtual void StopMusic() = 0;

        // Reprend la lecture de la musique qui a �t� mise en pause.
        virtual void ResumeMusic() = 0;

        // R�gle le volume global de la musique.
        virtual void SetVolume(int volume) = 0;

        // R�gle le volume d'un son sp�cifique identifi� par soundId.
        virtual void SetVolume(size_t soundId, int volume) = 0;

        // Nettoie et lib�re les ressources audio.
        virtual void Destroy() = 0;
    };
}
