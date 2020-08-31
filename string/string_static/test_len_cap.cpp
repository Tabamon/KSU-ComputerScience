//  String class test program
//
//  Tests: len_cap
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("hello");

        // VERIFY
        assert(str.capacity() == STRING_SIZE-1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('1');

        // VERIFY
        assert(str.length() == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");

        // VERIFY
        assert(str.length() == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("ciao");

        // VERIFY
        assert(str.length() == 4);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("hello world");

        // VERIFY
        assert(str.length() == 11);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str('\0');

        // VERIFY
        assert(str.length() == 0);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing len_cap." << std::endl;

}