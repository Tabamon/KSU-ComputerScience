//==============================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }
    
    bigint big1;
    bigint big2;

    while(in>>big1 && in>>big2){

        bigint result;
        std::cout << "bigint 1: " << big1 << " bigint 2: " << big2 << std::endl;
        result = big1 * big2;
        std::cout << big1 << " x " << big2 << " = " << result << std::endl;
    }
 
    in.close();
    return 0;
}

