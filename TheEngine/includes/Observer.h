#pragma once

namespace buki
{
	template<typename T1, typename T2>
	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(const T1& value, T2 other) = 0;
	};
}
