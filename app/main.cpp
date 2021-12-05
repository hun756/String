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


    return EXIT_SUCCESS;
}