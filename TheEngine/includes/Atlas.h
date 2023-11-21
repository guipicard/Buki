#pragma once
#include <Sprite.h>
#include <map>
#include <string>
#include <RectI.h>

namespace buki
{
    class Entity;

    class Atlas final : public Sprite
    {
    public:
        virtual ~Atlas() = default;
        Atlas();
        Atlas(Entity* parent);

        void AddFrame(const std::string& name, int x, int y, int w, int h);
        void SetFrame(const std::string& name);

    private:
        std::map<std::string, RectI> m_Frames;
    };
}
