#pragma once
#include <EKey.h>

namespace buki
{
    class IInput
    {
    public:
        virtual ~IInput() = default; // Destructeur virtuel par d�faut.

        virtual bool IsKeyPressed(EKey key) = 0; // V�rifie si la touche sp�cifi�e (key) est actuellement press�e.

        virtual bool IsKeyDown(EKey key) = 0; // V�rifie si la touche sp�cifi�e (key) est en position basse (activ�e).

        virtual bool IsKeyUp(EKey key) = 0; // V�rifie si la touche sp�cifi�e (key) est en position haute (d�sactiv�e).

        virtual bool IsButtonPressed(int button) = 0; // V�rifie si le bouton de la souris sp�cifi� (button) est actuellement press�.

        virtual bool IsButtonDown(int button) = 0; // V�rifie si le bouton de la souris sp�cifi� (button) est en position basse (activ�).

        virtual bool IsButtonUp(int button) = 0; // V�rifie si le bouton de la souris sp�cifi� (button) est en position haute (d�sactiv�).

        virtual void GetMousePosition(int* x, int* y) = 0; // R�cup�re la position actuelle de la souris, en enregistrant les coordonn�es dans x et y.

        virtual void ResetLateInputs() = 0; // R�initialise les �tats des entr�es qui ont �t� enregistr�es tardivement.

    protected:
        friend class Engine; // Donne un acc�s sp�cifique � la classe Engine pour utiliser les m�thodes prot�g�es.

        virtual void Update() = 0; // Met � jour l'�tat des entr�es. Cette m�thode est probablement appel�e � chaque cycle de la boucle principale du jeu.

        bool m_IsRunning = true; // Indique si le gestionnaire d'entr�e est actif.
    };
}
