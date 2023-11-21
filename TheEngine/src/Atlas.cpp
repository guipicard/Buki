#include <Atlas.h>
#include <Engine.h>

buki::Atlas::Atlas() : Atlas(nullptr)
{
}

buki::Atlas::Atlas(Entity* parent) : Sprite(parent)
{
}

void buki::Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
    m_Frames.emplace(name, RectI{ x, y, w, h });

    if (m_Frames.size() == 1)
    {
        SetFrame(name);
    }
}

void buki::Atlas::SetFrame(const std::string& name)
{
    RectI _src = m_Frames[name];
    m_Src.x = _src.x;
    m_Src.y = _src.y;
    m_Src.w = _src.w;
    m_Src.h = _src.h;
}
