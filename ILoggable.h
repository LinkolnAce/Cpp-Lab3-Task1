#pragma once
#include <string>
#include <fstream>

class ILoggable {
public:
	virtual void LogToScreen() = 0;
	virtual void LogToFile(const std::string& filename) = 0;
};