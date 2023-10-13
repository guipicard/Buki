#include "LogFile.h"
#include <ctime>


buki::LogFile::LogFile()
{
	 MyFile.open("./assets/LogFile.txt", std::ios_base::app);
	 time_t now = time(0);

	 std::cout << "Number of sec since January 1,1970 is:: " << now << std::endl;

	 tm* ltm = localtime(&now);

	 int year = 1900 + ltm->tm_year;
	 int mounth = 1 + ltm->tm_mon;
	 int day = ltm->tm_mday;
	 int hour = 5 + ltm->tm_hour;
	 int min = 30 + ltm->tm_min;
	 int sec = ltm->tm_sec;
	 MyFile << year << ":" << mounth << ":" << day << ":" << hour << "h" << min << "m" << sec << "s" << "\n" << std::endl;
}

buki::LogFile::~LogFile()
{
	MyFile << "\n" << "\n";
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
