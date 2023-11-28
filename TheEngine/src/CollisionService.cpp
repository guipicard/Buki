#include "CollisionService.h"
#include <math.h>
#include <Entity.h>

bool buki::CollisionService::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
    float vecX = px - cx;
    float vecY = py - cy;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= cr;
}

bool buki::CollisionService::CheckCircles(float c1x, float c1y, float c1r, float c2x, float c2y, float c2r)
{
    float vecX = c1x - c2x;
    float vecY = c1y - c2y;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= (c1r + c2r);
}

bool buki::CollisionService::CheckPointRect(float px, float py, float rx, float ry, float rw,
    float rh)
{
    return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}

bool buki::CollisionService::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x,
    float r2y, float r2w, float r2h)
{
    return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x && r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
}

bool buki::CollisionService::CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr)
{
    if (CheckPointRect(cx, cy, rx, ry, rw, rh))
    {
        return true;
    }

    float tx = cx;
    float ty = cy;

    if (tx < rx) tx = rx;
    if (tx > rx + rw) tx = rx + rw;
    if (ty < ry) ty = ry;
    if (ty > ry + rh) ty = ry + rh;

    return CheckPointCircle(tx, ty, cx, cy, cr);
}

void buki::CollisionService::AddToLayer(const std::string& layerName, Entity* entity)
{
    if (m_Layers.count(layerName) == 0)
    {
        m_Layers.emplace(layerName, std::vector<Entity*>());
    }

    m_Layers[layerName].push_back(entity);
}

bool buki::CollisionService::CollideWithLayer(Entity* entity, const std::string& layerName, Entity** other)
{
    *other = nullptr;

    if (m_Layers.count(layerName) > 0)
    {
        Point2D r1pos, r1size;
        Point2D r2pos, r2size;

        entity->GetPosition(r1pos);
        entity->GetSize(r1size);

        for (Entity* e : m_Layers[layerName])
        {
            e->GetPosition(r2pos);
            e->GetSize(r2size);

            if (CheckRects(r1pos.x, r1pos.y, r1size.x, r1size.y, r2pos.x, r2pos.y, r2size.x, r2size.y))
            {
                *other = e;
                return true;
            }
        }
    }

    return false;
}

void buki::CollisionService::Remove(Entity* entity)
{
    for (auto layer : m_Layers)
    {
        std::vector<Entity*>::iterator it = layer.second.begin();
        while (it != layer.second.end())
        {
            if (*it == entity)
            {
                layer.second.erase(it);
                return;
            }
            it++;
        }
    }
}
