#pragma once
#include "RectI.h"
#include "BukiContainers.h"

namespace buki
{
	struct Camera
	{
		Camera();
		~Camera();
		int width = 0;
		int height = 0;
		Vector2 position = Vector2::ZERO;
	};
}
