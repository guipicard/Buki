
#include "Atlas.h"
#include "Engine.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

buki::Atlas::Atlas(Entity* _entity) : Component(_entity) {}

void buki::Atlas::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
	m_Id = Graphics().LoadTexture(image);
	if (!m_Id) return;
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
					Graphics().DrawTexture(m_Id, _src, _dst, 0.0, Flip(), Color::White);
				}
			}
		}
	}
}

void buki::Atlas::Draw()
{
	DrawTiles(m_TileWidth, m_TileHeight);
}

TLayer buki::Atlas::CreateLayerFromCSV(std::string _file)
{

	TLayer newLayer = TLayer();

	std::ifstream myFile(_file);

	if (!myFile.is_open()) throw std::runtime_error("Could not open file");

	std::string line;
	int val;

	while (std::getline(myFile, line))
	{
		std::stringstream ss(line);
		int colIdx = 0;

		std::vector<int> row;
		while (ss >> val)
		{
			row.push_back(val + 1);

			if (ss.peek() == ',') ss.ignore();

			colIdx++;
		}
		newLayer.push_back(row);
	}
	myFile.close();

	return newLayer;
}

void buki::Atlas::AddLayer(std::string _name, TLayer _layer)
{
	for (auto it = m_Tilemap.begin(); it != m_Tilemap.end(); it++)
	{
		if ((it)->first == _name) return;
	}

	std::vector<RectI> layerColliders;
	for (int y = 0; y < _layer.size(); y++)
	{
		for (int x = 0; x < _layer[y].size(); x++)
		{
			int _index = _layer[y][x] - 1;
			if (_index >= 0)
			{
				RectI collider{
				x * m_TileWidth,
				y * m_TileHeight,
				m_TileWidth,
				m_TileHeight
				};
				layerColliders.push_back(collider);
			}
		}
	}
	Collision().AddLayer(_name, layerColliders);
	m_Tilemap.push_back(std::pair<std::string, TLayer>(_name, _layer));

}
