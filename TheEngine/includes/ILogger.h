#pragma once
#include <cstdlib>
#include <string>
#include <windows.h>

namespace buki {
    class ILogger
    {
    public:
        virtual ~ILogger() = default; // Destructeur virtuel par d�faut pour une gestion appropri�e de la polymorphie.

        virtual void LogError(std::string _text) = 0; // Journalise un message d'erreur. _text sp�cifie le contenu du message d'erreur.

        virtual void LogSdlError() = 0; // Journalise un message d'erreur sp�cifique � SDL. Cette m�thode peut �tre utilis�e pour capturer et afficher les erreurs g�n�r�es par SDL.

        virtual void LogWarning(std::string _text) = 0; // Journalise un message d'avertissement. _text sp�cifie le contenu du message d'avertissement.

        virtual void LogSuccess(std::string _text) = 0; // Journalise un message de succ�s. _text sp�cifie le contenu du message de succ�s.

        virtual void LogMessage(std::string _text) = 0; // Journalise un message g�n�rique. _text sp�cifie le contenu du message.

        virtual void LogMessage(size_t _text) = 0; // Surcharge de la m�thode LogMessage pour journaliser un message qui est un nombre (size_t). _text sp�cifie le nombre � journaliser.
    };
}
