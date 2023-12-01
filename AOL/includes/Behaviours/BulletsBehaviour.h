#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class BulletsBehaviour : public MonoBehaviour
	{
	public:
		BulletsBehaviour(Entity* entity);
		~BulletsBehaviour() = default;
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void SetDirection(std::string direction);
		void SetSpeed(int speed) { m_Speed = speed; }
		void SetDistance(float distance) { m_Distance = distance; }
		void SetPos(Point2D pos) { m_Start = pos; }
		Point2D GetVelocity() { return m_Velocity; }
	private:
		int m_Speed = 0;
		float m_Distance = 0.0f;
		Point2D m_Velocity = Point2D();
		Point2D m_Start = Point2D();
	};
}
