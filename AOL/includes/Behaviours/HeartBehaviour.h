#pragma once
#include "MonoBehaviour.h"

namespace buki
{
	class HeartBehaviour : public MonoBehaviour
	{
	public:
		HeartBehaviour(Entity* entity);
		~HeartBehaviour();
		virtual void Update(float dt) override;
		virtual void OnNotify(const std::string& value, Entity* other) override;
		void Charged() { m_Charges += 2; }
		int GetCharges() { return m_Charges; }
	private:
		int m_Charges = 0;
	};
}