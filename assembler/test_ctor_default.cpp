//  Stack class test program
//
//  Tests: Default Ctor
//

#include "stack.hpp"
#include "../string/string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> x;

        // VERIFY
        assert(x.empty());

        stack<String> stringStack;

        assert(stringStack.empty());
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default ctor." << std::endl;

}