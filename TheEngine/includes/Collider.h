#pragma once 
#include "Component.h"
#include "IUpdatable.h"
#include "Tilemap.h"
#include "Point2D.h"
#include <vector>
#include <string>

namespace buki
{
	class Tilemap;
	struct Point2D;
	class Collider : public IUpdatable, public IDrawable
	{
	public:
		virtual ~Collider() = default;
		virtual void CheckTileCollision() = 0;
		virtual void CheckCollision() = 0;
		void SetTilemap(Tilemap* tilemap) { 
			m_Tilemap = tilemap;
			m_TileIncludeLayers = m_Tilemap->GetColliderLayerNames();
			/*for (auto layer : m_Tilemap->GetColliderLayerNames())
			{
				AddTileIncludeLayer(layer);
			}*/
		}
		void AddTileIncludeLayer(std::string layer) { m_TileIncludeLayers.push_back(layer); }
		void RemoveTileIncludeLayer(std::string layer) { m_TileIncludeLayers.erase(std::remove(m_TileIncludeLayers.begin(), m_TileIncludeLayers.end(), layer), m_TileIncludeLayers.end()); }
		void AddIncludeLayer(std::string layer) { m_IncludeLayers.push_back(layer); }
		void RemoveIncludeLayer(std::string layer) { m_IncludeLayers.erase(std::remove(m_IncludeLayers.begin(), m_IncludeLayers.end(), layer), m_IncludeLayers.end()); }
	protected:
		Tilemap* m_Tilemap = nullptr;
		std::vector<std::string> m_TileIncludeLayers;
		std::vector<std::string> m_IncludeLayers;
		Point2D m_Offset;
		Point2D m_Size;
		const bool canDraw = true;
	};
}