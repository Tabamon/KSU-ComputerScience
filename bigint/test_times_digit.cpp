// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_digit(1);

        // Verify
        std::cout << bi << std::endl;
        assert(bi == 3);


    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1234);

        // Test 
        bi = bi.times_digit(2);

        // Verify
        std::cout << bi << std::endl;
        assert(bi == 2468);

        
    }

        {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12345678);

        // Test 
        bi = bi.times_digit(8);

        // Verify
        std::cout << bi << std::endl;
        assert(bi == 98765424);

        
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("12345678901");

        // Test 
        bi = bi.times_digit(9);

        // Verify
        //bi.debugPrint(std::cout);
        std::cout << bi << std::endl;
        assert(bi == "111111110109");
        
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;

}