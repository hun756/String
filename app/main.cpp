#include <iostream>
#include <cstdlib>

#include "string.hpp"
#include "stringConfig.h"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main()
{
    std::cout << "C++ String Library" << PROJECT_VERSION_MAJOR << "."
            << PROJECT_VERSION_MINOR << std::endl;

    kor::String str{"merhaba"};

    std::cout << str.c_str() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str.capacity() << std::endl;

    auto _val = str.toCharArray();

    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << _val[i] << std::endl;
    }


    return EXIT_SUCCESS;
}