#include "Atlas.h"
#include "Engine.h"


buki::Atlas::Atlas(Entity* _entity) : Sprite(_entity) {}

void buki::Atlas::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
	m_AssetPath = image;
	m_Id = buki::Engine::GetInstance()->Graphics().LoadTexture(m_AssetPath);

	for (int i = 0; i < count; i++)
	{
		int _y = i / col;
		int _x = i - _y * col;
		RectI _tile(
			_x * tileW,
			_y * tileH,
			tileW,
			tileH);
		m_Tileset.push_back(_tile);
	}
	m_TileWidth = tileW;
	m_TileHeight = tileH;
}

void buki::Atlas::RenderFrame()
{
}

void buki::Atlas::DrawTiles(int tileW, int tileH)
{
	for (auto layer : m_Tilemap)
	{
		for (int y = 0; y < layer.second.size(); y++)
		{
			for (int x = 0; x < layer.second[y].size(); x++)
			{
				int _index = layer.second[y][x] - 1;
				if (_index >= 0)
				{
					RectI _src = m_Tileset[_index];
					RectF _dst{
					x * tileW,
					y * tileH,
					tileW,
					tileH
					};
					buki::Engine::GetInstance()->Graphics().DrawTexture(m_Id, _src, _dst, 0.0, Flip(), Color::White);
				}
			}
		}
	}
}

void buki::Atlas::Draw()
{
	DrawTiles(m_TileWidth, m_TileHeight);
}

TLayer buki::Atlas::CreateLayerFromCVS(std::vector<int> data)
{
	TLayer newLayer = TLayer();
	std::vector<int> newRow = std::vector<int>();
	for (int i = 0; i < data.size(); i++)
	{
		newRow.push_back(data[i]);
		if ((i + 1) % m_LayerLenght == 0 && i > 0)
		{
			newLayer.push_back(newRow);
			newRow = std::vector<int>();
		}
	}
	return newLayer;
}

void buki::Atlas::AddLayer(std::string _name, TLayer _layer)
{
	m_Tilemap.emplace(_name, _layer);
}
