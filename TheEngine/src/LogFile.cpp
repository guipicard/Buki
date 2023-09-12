#include "LogFile.h"

buki::LogFile::LogFile()
{
	 MyFile.open("LogFile.txt");
}

buki::LogFile::~LogFile()
{
	MyFile.close();
}

void buki::LogFile::LogError(std::string _text)
{
	MyFile << "ERROR: " << _text << std::endl;
}

void buki::LogFile::LogWarning(std::string _text)
{
	MyFile << "Warning: " << _text << std::endl;
}

void buki::LogFile::LogSuccess(std::string _text)
{
	MyFile << "Success: " << _text << std::endl;
}

void buki::LogFile::LogMessage(std::string _text)
{
	MyFile << _text << std::endl;
}

void buki::LogFile::LogMessage(size_t _text)
{
	MyFile << _text << std::endl;
}
