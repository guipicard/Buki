#pragma once
#include "Sprite.h"
#include <map>

namespace buki
{
	struct Atlas : public Sprite
	{
		virtual ~Atlas() = default;
		Atlas(Entity* entity);
		virtual void Draw(float alpha) override;
		void AddDestination(std::string source, const int x, const int y);
		void AddSource(const std::string key, const RectI value);
		void GetTextureSize(int* x, int* y);
		void SetTileSize(const int x, const int y);
	private:
		std::vector<std::vector<std::string>> destinations = { {""} };
		std::map<std::string, RectI> sources = std::map<std::string, RectI>();
	};
}
