#pragma once
#include "Sprite.h"
#include <cstdlib>

typedef std::vector<std::vector<int>> TLayer;
typedef std::vector<std::pair<std::string, TLayer>> TTilemap;
typedef std::vector<RectI> TTileset;

namespace buki
{
	class Atlas : public Component, public IDrawable
	{
	public:
		Atlas(Entity* _entity);
		void LoadTileset(const std::string& image, int tileW, int tileH, int col, int count);
		void RenderFrame();
		void DrawTiles(int tileW, int tileH);
		void Draw();
		TLayer CreateLayerFromCSV(std::string _file);
		void AddLayer(std::string _name, TLayer _layer);
	private:
		size_t m_Id = 0;
		TTilemap m_Tilemap;
		TTileset m_Tileset;
		int m_TileWidth = 0;
		int m_TileHeight = 0;
	};
}
