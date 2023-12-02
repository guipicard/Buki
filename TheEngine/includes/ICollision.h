#pragma once
#include <cstdlib>
#include <vector>
#include <string>

namespace buki
{
    class Entity;

    class ICollision
    {
    public:
        virtual ~ICollision() = default; // Destructeur virtuel par d�faut.

        // V�rifie si un point est � l'int�rieur d'un cercle.
        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) = 0;

        // V�rifie si deux cercles se chevauchent.
        virtual bool CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r) = 0;

        // V�rifie si un point est � l'int�rieur d'un rectangle.
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) = 0;

        // V�rifie si deux rectangles se chevauchent.
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) = 0;

        // V�rifie si un rectangle et un cercle se chevauchent.
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) = 0;

        // Ajoute une entit� � une couche de collision sp�cifi�e.
        virtual void AddToLayer(const std::string& layerName, Entity* entity) = 0;

        // V�rifie si une entit� entre en collision avec une autre entit� dans une couche sp�cifi�e.
        virtual bool CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other) = 0;

        // Retire une entit� du syst�me de collision.
        virtual void Remove(Entity* entity) = 0;
    };
}
