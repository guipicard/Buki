#pragma once
namespace buki {
	class IShape
	{
	public:
		virtual ~IShape() = default;
		virtual void Draw() = 0;
		virtual void SetPosition(float x, float y) = 0;
		virtual float GetPosX() = 0;
		virtual float GetPosY() = 0;
	};
}
