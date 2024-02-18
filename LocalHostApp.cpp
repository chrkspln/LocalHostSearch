#include "System.h"
// я не впевнена чи iostream тут треба бо я його уже включила в System.cpp
#include <iostream>

int main()
{
    // юзер інпут
    std::string input_file{};
    std::cout << "hello! enter file name here: ";
    std::cin >> input_file;
    
    // чищу буфер
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // пошук самого файла
    const auto found_path = System::find_file_path(input_file);
    std::cout << found_path << '\n';

    return 0;
}
