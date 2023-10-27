#include "Atlas.h"
#include "Engine.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


buki::Atlas::Atlas(Entity* _entity) : Sprite(_entity) {}

void buki::Atlas::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
	m_AssetPath = image;
	m_Id = Graphics().LoadTexture(m_AssetPath);
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

void buki::Atlas::AddMapFile(std::string _path)
{
	m_MapPath = _path;
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

TLayer buki::Atlas::CreateLayerFromCSV(std::string _file)
{

	TLayer newLayer = TLayer();
	std::vector<int> newRow = std::vector<int>();
	std::ifstream file(_file);

	// Create a vector of <string, int vector> pairs to store the result
	std::vector<std::pair<std::string, std::vector<int>>> result;

	// Create an input filestream
	std::ifstream myFile(_file);

	// Make sure the file is open
	if (!myFile.is_open()) throw std::runtime_error("Could not open file");

	// Helper vars
	std::string line, colname;
	int val;

	// Read the column names
	if (myFile.good())
	{
		// Extract the first line in the file
		std::getline(myFile, line);

		// Create a stringstream from line
		std::stringstream ss(line);

		// Extract each column name
		while (std::getline(ss, colname, ',')) {

			// Initialize and add <colname, int vector> pairs to result
			result.push_back({ colname, std::vector<int> {} });
		}
	}

	// Read data, line by line
	while (std::getline(myFile, line))
	{
		// Create a stringstream of the current line
		std::stringstream ss(line);

		// Keep track of the current column index
		int colIdx = 0;

		// Extract each integer
		while (ss >> val) {

			// Add the current integer to the 'colIdx' column's values vector
			result.at(colIdx).second.push_back(val);

			// If the next token is a comma, ignore it and move on
			if (ss.peek() == ',') ss.ignore();

			// Increment the column index
			colIdx++;
		}
	}
	myFile.close();
	for (auto line : result)
	{
		newLayer.push_back(line.second);
	}

	return newLayer;
}

void buki::Atlas::AddLayer(std::string _name, TLayer _layer)
{
	for (auto it = m_Tilemap.begin(); it != m_Tilemap.end(); it++)
	{
		if ((it)->first == _name) return;
	}
	m_Tilemap.push_back(std::pair<std::string, TLayer>(_name, _layer));

}
