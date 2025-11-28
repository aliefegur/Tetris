#include "File.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string File::ReadFile(const std::string& path)
{
	std::ostringstream oss;
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << path << std::endl;
		return "";
	}

	oss << file.rdbuf();
	return oss.str();
}
