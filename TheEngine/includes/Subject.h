#pragma once
#include "Observer.h"

namespace buki
{
	template<typename T1, typename T2>
	class Subject
	{
	public:
		void AddListener(Observer<T1, T2>* o)
		{
			m_Observers.push_back(o);
		}
		void RemoveListener(Observer<T1, T2>* o)
		{
			m_Observers.erase(std::remove(m_Observers.begin(), m_Observers.end(), o), m_Observers.end());
		}
		void Invoke(const T1 value, T2 other)
		{
			for (Observer<T1, T2>* o : m_Observers)
			{
				o->OnNotify(value, other);
			}
		}
	private:
		std::vector<Observer<T1, T2>*> m_Observers;
	};
}
