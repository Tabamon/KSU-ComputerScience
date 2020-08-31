#ifndef DEFAULT_CTOR
#define DEFAULT_CTOR
#include <iostream>
#include <cassert>
#include "string.hpp"

int main (){
    std::cout << "testing default constructor" << std::endl;
    {
        String test;
        assert(test == '\0');
    }

    {
        String test1;
        String test2;
        assert(test1==test2);
    }
    std::cout << "DONE teting default constructor" << std::endl;
}

#endif