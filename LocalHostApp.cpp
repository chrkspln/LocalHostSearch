#include "System.h"
#include <iostream>

int main()
{
    std::string input_file{};
    std::cout << "hello! enter file name here: ";
    std::cin >> input_file;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    const auto found_path = System::find_file_path(input_file);
    std::cout << found_path << '\n';

    return 0;
}