#include "System.h"
#include <iostream>

// тут я визначаю чи в юзера вінда чи лінукс аби правильно почати пошук
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

// функція пошуку
std::filesystem::path System::find_file_path(const std::string& file_name)
{
	// тут я через фор пробігаюсь по n-нній кількості directory_entry
	// за виключенням тих директорій які потребують права адміна
	for (const auto& entry : std::filesystem::recursive_directory_iterator(System::starting_point,
		std::filesystem::directory_options::skip_permission_denied)) {
		try {
			// порівнюю ім'я файла (тут і директорії порівнюються але за умови
			// шо юзер не дибіл і ввів екстеншн файла то все буде норм)
			if (entry.path().filename() == file_name) {
				// повертаю шлях файла назву якого ввів юзер
				return entry.path();
			}
		}
		// якшо шось іде по пизді то виводжу ексепшн
		// але взагалі єдиний ексепшн цього коду наразі це якшо файл дуже далеко
		// знаходиться на компі тоді там просто по часу програма не встигає
		// його знайти. буду робити треди
		catch (std::exception& ex) {
			std::cerr << "Error: " << ex.what() << '\n';
		}
	}
	// якшо програма не знайшла файл - виводиться пустий рядок
	// треба буде зробити можливість шукати файл знову через do-while
	return {};
}
