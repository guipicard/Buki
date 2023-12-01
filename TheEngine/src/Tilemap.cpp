#include "Tilemap.h"
#include <Engine.h>
#include <fstream>
#include <sstream>

buki::Tilemap::Tilemap() : Tilemap(nullptr)
{
}

buki::Tilemap::Tilemap(Entity* parent) : Component(parent)
{
}

void buki::Tilemap::Draw()
{
	for (auto layer : m_Tilemap)
	{
		for (int y = 0; y < m_Height; y++)
		{
			for (int x = 0; x < m_Width; x++)
			{
				int _idx = layer.second[y][x];

				if (_idx > 0)
				{
					_idx -= 1;
					int _w = m_TileWidth * m_ScaleFactor;
					int _h = m_TileHeight * m_ScaleFactor;
					RectF _dst = {
						static_cast<float>(x * _w),
						static_cast<float>(y * _h),
						static_cast<float>(_w),
						static_cast<float>(_h)
					};

					buki::Engine::GetInstance().Graphics().DrawTexture(
						m_TilesetId, m_Tileset[_idx],
						_dst, 0.0, { false, false }, Color::WHITE);
				}
			}
		}
	}
}

bool buki::Tilemap::CheckPointRect(float px, float py, float rx, float ry, float rw,
	float rh)
{
	return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}

bool buki::Tilemap::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
	float vecX = px - cx;
	float vecY = py - cy;
	float d = sqrtf((vecX * vecX) + (vecY * vecY));

	return d <= cr;
}

void buki::Tilemap::Load(const std::string& filename, int mapW, int mapH, int tileW, int tileH)
{
	auto& graphics = Engine::GetInstance().Graphics();
	m_TilesetId = graphics.LoadTexture(filename);
	m_TileWidth = tileW;
	m_TileHeight = tileH;
	m_Width = mapW;
	m_Height = mapH;

	int _w, _h;
	graphics.GetTextureSize(m_TilesetId, &_w, &_h);

	int _tilePerRow = _w / m_TileWidth;
	int _tilePerCol = _h / m_TileHeight;
	int _tileCount = _tilePerRow * _tilePerCol;

	for (int i = 0; i < _tileCount; i++)
	{
		int _ty = i / _tilePerRow;
		int _tx = i - _ty * _tilePerRow;

		RectI _tile = {
			_tx * m_TileWidth,
			_ty * m_TileHeight,
			m_TileWidth,
			m_TileHeight
		};

		m_Tileset.push_back(_tile);
	}
}

void buki::Tilemap::AddLayer(const std::string& layer, TLayer tiles, bool isColliding)
{
	if (m_Tilemap.count(layer) == 0)
	{
		m_Tilemap.emplace(layer, tiles);
		if (isColliding) m_ColliderLayers.push_back(layer);
	}
}

buki::TLayer buki::Tilemap::GetLayer(const std::string& name)
{
	if (m_Tilemap.count(name) > 0)
	{
		return m_Tilemap[name];
	}

	return TLayer{};
}

int Clamp(int value, const int min, const int max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}

	return value;
}

bool buki::Tilemap::IsBoxColliding(const std::string& layer, float x, float y, float w, float h, Point2D* tileIndex)
{
	w--;
	h--;
	const int tLeftTile = Clamp(static_cast<int>(x / m_TileWidth), 0, m_Width);
	const int tRightTile = Clamp(static_cast<int>((x + w) / m_TileWidth), 0, m_Width);
	const int tTopTile = Clamp(static_cast<int>(y / m_TileHeight), 0, m_Height);
	const int tBottomTile = Clamp(static_cast<int>((y + h) / m_TileHeight), 0, m_Height);
	const int tCenterX = Clamp(static_cast<int>((x + (w / 2)) / m_TileHeight), 0, m_Height);
	const int tCenterY = Clamp(static_cast<int>((y + (h / 2)) / m_TileHeight), 0, m_Height);


	*tileIndex = Point2D(tCenterX, tCenterY);
	for (int i = tLeftTile; i <= tRightTile; i++)
	{
		for (int j = tTopTile; j <= tBottomTile; j++)
		{
			if (i < m_Width && j < m_Height)
			{
				if (m_Tilemap[layer][j][i] != 0)
				{
					return true;
				}
			}
		}
	}
	return false;
}

buki::TLayer buki::Tilemap::CreateLayerFromCSV(std::string _file)
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
// 180 - (((n - 2) * 180) / 2n) == angle