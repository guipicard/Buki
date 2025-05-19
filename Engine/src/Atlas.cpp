#include "Atlas.h"
#include "Component.h"
#include "Entity.h"
#include "Engine.h"


buki::Atlas::Atlas(Entity* entity) : Sprite(entity)
{
}

void buki::Atlas::Draw(float alpha)
{
	//Log().LogMessage("Draw");
	Vector2 entityPosition = m_Entity->GetTransform()->GetPosition();
	int tilesX = (int)destinations[0].size();
	int tilesY = (int)destinations.size();
	Vector2 fullSize = { m_Size.x * tilesX, m_Size.y * tilesY };
	for (int j = 0; j < tilesY; j++)
	{
		for (int i = 0; i < tilesX; i++)
		{
			RectF _dst
			(
				entityPosition.x + m_Position.x + (m_Size.x * i) - (fullSize.x * 0.5f),
				entityPosition.y + m_Position.y + (m_Size.y * j) - (fullSize.y * 0.5f),
				m_Size.x,
				m_Size.y
			);
			Graphics().DrawTexture(m_Id, sources[destinations[j][i]], _dst, Color::WHITE);
		}
	}

}

void buki::Atlas::AddDestination(std::string source, const int x, const int y)
{
	destinations[y][x] = source;
}

void buki::Atlas::AddSource(const std::string key, const RectI value)
{
	sources[key] = value;
}

void buki::Atlas::GetTextureSize(int* x, int* y)
{
	Graphics().GetTextureSize(m_Id, x, y);
}

void buki::Atlas::SetTileSize(const int x, const int y)
{
	destinations = std::vector<std::vector<std::string>>();
	for (int j = 0; j < y; j++)
	{
		destinations.push_back(std::vector<std::string>());
		for (int i = 0; i < x; i++)
		{
			destinations[j].push_back("");
		}
	}
}
