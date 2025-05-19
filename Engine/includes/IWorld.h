#pragma once
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

namespace buki
{
    struct Entity;
    struct IScene;
    struct Manifold;
    struct Vector2;

    struct IWorld
    {
        virtual ~IWorld() = default; // Destructeur virtuel par d�faut.

        virtual void Start() = 0; // Initialise le monde du jeu.

        virtual void FixedUpdate(float dt) = 0; 

        virtual void Update(float dt) = 0; // Met � jour le monde du jeu, avec dt repr�sentant le temps �coul� depuis la derni�re mise � jour.

        virtual void Render(float alpha) = 0; // Dessine le monde du jeu � l'�cran.

        virtual void Destroy() = 0; // Nettoie et lib�re les ressources utilis�es par le monde du jeu.

        virtual Entity* Create(const std::string& name) = 0; // Cr�e une nouvelle entit� avec un nom sp�cifi�.

        virtual void Add(Entity* _entity) = 0; // Ajoute une entit� au monde du jeu.

        virtual void Remove(Entity* _entity) = 0; // Supprime une entit� du monde du jeu.

        virtual Entity* Find(std::string _name) = 0; // Recherche une entit� dans le monde du jeu.

        virtual std::vector<Entity*> FindAll(std::string _name) = 0; // Recherche des entit�s au meme nom dans le monde du jeu.

        virtual void Load(const std::string& scene) = 0; // Charge une sc�ne sp�cifi�e par son nom.

        virtual void SetLoadScene(const std::string& scene) = 0; // D�finit la sc�ne � charger.

        virtual void Unload() = 0; // D�charge la sc�ne actuelle.

        virtual void Register(const std::string& name, IScene* scene) = 0; // Enregistre une sc�ne avec un nom sp�cifique dans le monde du jeu.

        virtual void SetCurrentSceneName(std::string _name) = 0; // D�finit le nom de la sc�ne actuelle.

        virtual IScene* GetCurrentScene() = 0; // Retourne la sc�ne actuelle.

        virtual std::string GetCurrentSceneName() = 0; // Retourne le nom de la sc�ne actuelle.

        virtual void LoadNextScene() = 0; // Charge la sc�ne suivante dans la s�quence d�finie.

        virtual void IntegrateForces(Entity* e, float dt) = 0;

        virtual  void IntegrateVelocity(Entity* e, float dt) = 0;

        virtual void GeneratePairs(float dt, Vector2 gravity) = 0; // Generate manifolds of objects that could be colliding

        virtual void CheckCollisions(Manifold* M, float dt, Vector2 gravity) = 0; // Dispatches to the right colision check

        virtual std::vector<Entity*> GetEntitiesInWorld() = 0; // Get All enties present in the world

        virtual void SortEntities() = 0; // sorts Entities present in the World by Z axis

        
    };
}
