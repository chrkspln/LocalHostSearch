#pragma once
#include <string>
#include <filesystem>
class System
{
public:
	static std::filesystem::path find_file_path(const std::string& file_name);
	static std::filesystem::directory_entry starting_point;
};
