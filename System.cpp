#include "System.h"
#include <iostream>

#ifdef _WIN64
#include <filesystem>
std::filesystem::directory_entry System::starting_point{ "C:\\" };
#elif _WIN32
#include <filesystem>
std::filesystem::directory_entry System::starting_point{ "C:\\" };
#elif __linux__
#include <filesystem>
std::filesystem::directory_entry System::starting_point{ "/" };
#endif

std::filesystem::path System::find_file_path(const std::string& file_name)
{
	for (const auto& entry : std::filesystem::recursive_directory_iterator(System::starting_point, std::filesystem::directory_options::skip_permission_denied)) {
		try {
			if (entry.path().filename() == file_name) {
				return entry.path();
			}
		}
		catch (std::exception& ex) {
			std::cerr << "Error: " << ex.what() << '\n';
		}
	}
	return {};
}