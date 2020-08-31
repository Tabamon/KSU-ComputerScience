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
        String  str("MY name is Lorenzo");

        // TEST
        String result = str.substr(11,18);

        // VERIFY
        assert(str    == "MY name is Lorenzo");
        assert(result == "Lorenzo");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("1234567890");

        // TEST
        String result = str.substr(1,2);

        // VERIFY
        assert(str    == "1234567890");
        assert(result == "23");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("1");

        // TEST
        String result = str.substr(0,0);

        // VERIFY
        assert(str    == "1");
        assert(result == "1");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");

        // TEST
        String result = str.substr(0,5);

        // VERIFY
        assert(str    == "qwerty");
        assert(result == "qwerty");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hello World");

        // TEST
        String result = str.substr(4,6);

        // VERIFY
        assert(str    == "Hello World");
        assert(result == "o W");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("my name is \nLorenzo\tToscano");

        // TEST
        String result = str.substr(0,0);

        // VERIFY
        assert(str    == "name is \nLorenzo\tToscano");
        assert(result == "my name is \nLorenzo\tToscano");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing substr." << std::endl;
}