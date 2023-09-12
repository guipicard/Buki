#pragma once
#include "ILogger.h"
#include <fstream>
#include <iostream>

namespace buki {
	class LogFile : public ILogger {
	public:
		LogFile();
		virtual ~LogFile() override;
		virtual void LogError(std::string _text) override;
		virtual void LogWarning(std::string _text) override;
		virtual void LogSuccess(std::string _text) override;
		virtual void LogMessage(std::string _text) override;
		virtual void LogMessage(size_t _text) override;
	private:
		std::ofstream MyFile;
	};
}