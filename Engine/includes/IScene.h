#pragma once
#include <string>

namespace buki
{
    struct Entity;

    struct IScene
    {
        virtual ~IScene() = default; // Destructeur virtuel par d�faut pour une gestion appropri�e de la polymorphie.

        virtual void Load() = 0; // Charge les ressources et initialise la sc�ne. Doit �tre impl�ment�e pour d�finir le comportement sp�cifique au chargement de la sc�ne.

        virtual Entity* Instantiate(const std::string _name) = 0; // Cr�e et retourne une nouvelle instance de l'entit� sp�cifi�e par _name. Cette m�thode doit �tre impl�ment�e pour g�rer la cr�ation d'entit�s dans la sc�ne.

        //virtual Entity* Instantiate(const std::string _name) = 0; // Cr�e et retourne une nouvelle instance de l'entit� sp�cifi�e par _name. Cette m�thode doit �tre impl�ment�e pour g�rer la cr�ation d'entit�s dans la sc�ne.
    
        virtual void OnWindowResize() = 0;

        virtual void OnStart() = 0;

        virtual void OnStop() = 0;
    };
}
