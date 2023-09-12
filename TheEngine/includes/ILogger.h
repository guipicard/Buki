#pragma once
#include <cstdlib>
#include <string>
#include <windows.h>

namespace buki {
	class ILogger
	{
	public:
		virtual ~ILogger() = default;
		virtual void LogError(std::string _text) = 0;
		virtual void LogWarning(std::string _text) = 0;
		virtual void LogSuccess(std::string _text) = 0;
		virtual void LogMessage(std::string _text) = 0;
		virtual void LogMessage(size_t _text) = 0;
	};
}