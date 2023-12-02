#pragma once
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include "Entity.h"
#include "BaseScene.h"

namespace buki
{
    class IWorld
    {
    public:
        virtual ~IWorld() = default; // Destructeur virtuel par d�faut.

        virtual void Start() = 0; // Initialise le monde du jeu.

        virtual void Update(float dt) = 0; // Met � jour le monde du jeu, avec dt repr�sentant le temps �coul� depuis la derni�re mise � jour.

        virtual void Render() = 0; // Dessine le monde du jeu � l'�cran.

        virtual void Destroy() = 0; // Nettoie et lib�re les ressources utilis�es par le monde du jeu.

        virtual Entity* Create(const std::string& name) = 0; // Cr�e une nouvelle entit� avec un nom sp�cifi�.

        virtual Entity* Create(const std::string& name, float _x, float _y, float _w, float _h) = 0; // Cr�e une nouvelle entit� avec un nom et une position/dimension sp�cifi�s.

        virtual void Add(Entity* _entity) = 0; // Ajoute une entit� au monde du jeu.

        virtual void Remove(Entity* _entity) = 0; // Supprime une entit� du monde du jeu.

        virtual void Find() = 0; // Recherche des entit�s dans le monde du jeu (� compl�ter avec des param�tres sp�cifiques).

        virtual void Load(const std::string& scene) = 0; // Charge une sc�ne sp�cifi�e par son nom.

        virtual void SetLoadScene(const std::string& scene) = 0; // D�finit la sc�ne � charger.

        virtual void Unload() = 0; // D�charge la sc�ne actuelle.

        virtual void Register(const std::string& name, IScene* scene) = 0; // Enregistre une sc�ne avec un nom sp�cifique dans le monde du jeu.

        virtual void SetCurrentSceneName(std::string _name) = 0; // D�finit le nom de la sc�ne actuelle.

        virtual IScene* GetCurrentScene() = 0; // Retourne la sc�ne actuelle.

        virtual std::string GetCurrentSceneName() = 0; // Retourne le nom de la sc�ne actuelle.

        virtual void LoadNextScene() = 0; // Charge la sc�ne suivante dans la s�quence d�finie.
    };
}
