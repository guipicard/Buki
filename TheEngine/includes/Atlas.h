#pragma once
#include "Sprite.h"

typedef std::vector<std::vector<int>> TLayer;
typedef std::map<std::string, TLayer> TTilemap;
typedef std::vector<RectI> TTileset;

namespace buki
{
	class Atlas : public Sprite
	{
	public:
		Atlas(Entity* _entity);
		void LoadTileset(const std::string& image, int tileW, int tileH, int col, int count);
		void RenderFrame();
		void DrawTiles(int tileW, int tileH);
		void Draw();
		TLayer CreateLayerFromCSV(std::vector<int> data);
		void AddLayer(std::string _name, TLayer _layer);
		void SetLayerLength(int _length) { m_LayerLenght = _length; }
	private:
		TTilemap m_Tilemap;
		TTileset m_Tileset;
		int m_LayerLenght = 0;
		int m_TileWidth = 0;
		int m_TileHeight = 0;
	};
}
