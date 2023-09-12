#include "LogConsole.h"
#include <cstdlib>
#include <iostream>

buki::LogConsole::LogConsole()
{
	AllocConsole();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}

buki::LogConsole::~LogConsole()
{
	FreeConsole();
}

void buki::LogConsole::LogError(std::string _text)
{
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_RED));
	std::cout << "ERROR: " << _text << std::endl;
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_WHITE));

}

void buki::LogConsole::LogWarning(std::string _text)
{
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_YELLOW));
	std::cout << "Warning: " << _text << std::endl;
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_WHITE));
}

void buki::LogConsole::LogSuccess(std::string _text)
{
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_GREEN));
	std::cout << "Success: " << _text << std::endl;
	SetConsoleTextAttribute(hConsole, static_cast<int>(EColor::ECOLOR_WHITE));
}

void buki::LogConsole::LogMessage(std::string _text)
{
	std::cout << _text << std::endl;
}

void buki::LogConsole::LogMessage(size_t _text)
{
	std::cout << _text << std::endl;
}

