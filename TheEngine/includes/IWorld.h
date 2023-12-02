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
        virtual ~IWorld() = default; // Destructeur virtuel par défaut.

        virtual void Start() = 0; // Initialise le monde du jeu.

        virtual void Update(float dt) = 0; // Met à jour le monde du jeu, avec dt représentant le temps écoulé depuis la dernière mise à jour.

        virtual void Render() = 0; // Dessine le monde du jeu à l'écran.

        virtual void Destroy() = 0; // Nettoie et libère les ressources utilisées par le monde du jeu.

        virtual Entity* Create(const std::string& name) = 0; // Crée une nouvelle entité avec un nom spécifié.

        virtual Entity* Create(const std::string& name, float _x, float _y, float _w, float _h) = 0; // Crée une nouvelle entité avec un nom et une position/dimension spécifiés.

        virtual void Add(Entity* _entity) = 0; // Ajoute une entité au monde du jeu.

        virtual void Remove(Entity* _entity) = 0; // Supprime une entité du monde du jeu.

        virtual void Find() = 0; // Recherche des entités dans le monde du jeu (à compléter avec des paramètres spécifiques).

        virtual void Load(const std::string& scene) = 0; // Charge une scène spécifiée par son nom.

        virtual void SetLoadScene(const std::string& scene) = 0; // Définit la scène à charger.

        virtual void Unload() = 0; // Décharge la scène actuelle.

        virtual void Register(const std::string& name, IScene* scene) = 0; // Enregistre une scène avec un nom spécifique dans le monde du jeu.

        virtual void SetCurrentSceneName(std::string _name) = 0; // Définit le nom de la scène actuelle.

        virtual IScene* GetCurrentScene() = 0; // Retourne la scène actuelle.

        virtual std::string GetCurrentSceneName() = 0; // Retourne le nom de la scène actuelle.

        virtual void LoadNextScene() = 0; // Charge la scène suivante dans la séquence définie.
    };
}
