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
        bi = bi.times_10(0);

        // Verify
        assert(bi == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1234);

        // Test 
        bi = bi.times_10(1);

        // Verify
        assert(bi == 12340);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12345678);

        // Test 
        bi = bi.times_10(2);

        // Verify
        assert(bi == 1234567800);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == 3);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times_10(0);

        // Verify
        assert(bi == 3);
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}

