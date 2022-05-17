#include <iostream>
#include <cstdlib>

#define ENABLE_COMPABILITY_W_STD_VECTOR
#define ENABLE_COMPABILITY_W_STD_STRING

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

    std::cout << "Operator << " << str << std::endl;
    str += " hi";
    std::cout << "Operator << " << str << std::endl;

    std::cout << str.c_str() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << str.capacity() << std::endl;

    auto _val = str.toCharArray();

    for (size_t i = 0; i < str.size(); ++i) {
        std::cout << _val[i] << std::endl;
    }
    
    int i = 1;

    const char* cstring = str.c_str();

    std::cout << "Addres is : " << reinterpret_cast<const void*>( cstring ) << std::endl;
    std::cout << "Addres is : " << reinterpret_cast<const void*>( str.c_str() ) << std::endl;

    // error printing m value from ascii
    // std::cout << "Addres is : iterator begin " << (void*)(*(str.begin()))<< std::endl;

    for (auto value = str.begin(); value != str.end(); ++value)
    {
        std::cout << &value << std::endl;
        std::cout << *value << std::endl;
        std::cout << i++ << std::endl;
    }

    for (kor::String::const_iterator value = str.begin(); value != str.end(); ++value)
    {
        std::cout << *value << std::endl;
    }

    std::cout << "try reverse iterator..!" << std::endl;
     for (auto value = str.rbegin(); value != str.rend(); ++value)
    {
        std::cout << *value << std::endl;
    }

    std::cout << "try reverse iterator..!" << std::endl;
     for (kor::String::const_reverse_iterator value = str.rbegin(); value != str.rend(); ++value)
    {
        std::cout << *value << std::endl;
    }

    std::cout << "try vector convertion" << std::endl;

    std::vector<char> charvec = str;

    std::string _a = str;

    std::cout << "converting to std_string = " << _a << std::endl;

    for (size_t i = 0; i <charvec.size(); ++i) {
        std::cout << charvec[i] << " , ";
    }
    
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
} 