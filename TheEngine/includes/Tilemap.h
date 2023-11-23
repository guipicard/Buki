#pragma once
#include <vector>
#include <map>
#include <string>
#include <RectI.h>
#include <Component.h>
#include <IDrawable.h>

namespace buki
{
    typedef std::vector<std::vector<int>> TLayer;
    typedef std::map<std::string, TLayer> TTilemap;
    typedef std::vector<RectI> TTileset;

    class Tilemap : public Component, public IDrawable
    {
    public:
        virtual ~Tilemap() = default;
        Tilemap();
        Tilemap(Entity* parent);

        virtual void Draw() override;

        void Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH);
        void AddLayer(const std::string& layer, TLayer tiles);
        TLayer GetLayer(const std::string& name);
        bool IsColliding(const std::string& layer, float x, float y, float w, float h, int* tileIndex);
        TLayer CreateLayerFromCSV(std::string _file);


    private:
        TTilemap m_Tilemap;
        int m_Width = 0;
        int m_Height = 0;
        size_t m_TilesetId = 0;
        int m_TileWidth = 0;
        int m_TileHeight = 0;
        TTileset m_Tileset;
        int m_ScaleFactor = 1;
    };
}
