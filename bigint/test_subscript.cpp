// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    //Add test cases!!
//1
    {
        bigint big("20");
        assert(big[1]==2);
    }
//2
    {
        bigint big("123");
        assert(big[2]==1);
    }
//3
    {
        bigint big("9856");
        assert(big[0]==6);
    }
//4
    {
        bigint big;
        assert(big[50]==0);
    }
//5
    {
        bigint big("96358");
        assert(big[4]==9);
    }
//6
    {
        bigint big("13216549");
        assert (big[7]==1);
    }

    std::cout << "Done testing subscript." << std::endl;
}