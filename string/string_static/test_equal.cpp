//  String class test program
//
//  Tests: XXX
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
        String  str;
        String  str2;

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("MY name is Lorenzo");
        String  str2("MY name is Lorenzo");

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("1234567890");
        String  str2("1234567890");

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('a');
        String  str2('a');

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");
        String  str2("qwerty");

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hello World");
        String  str2("Hello World!");

        // VERIFY
        assert(!(str == str2));
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Lorenzo\tToscano");
        String  str2("Lorenzo\tToscano");

        // VERIFY
        assert(str    == str2);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing equal." << std::endl;
}
