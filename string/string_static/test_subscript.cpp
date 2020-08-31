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

        // TEST
        str[0]='j';
        str[1]=END;

        // VERIFY
        assert(str == "j");
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("hello");

        // TEST
        str[0]='j';

        // VERIFY
        assert(str == "jello");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('1');

        // TEST
        str[0]='2';

        // VERIFY
        assert(str == '2');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");

        // TEST
        str[5]='z';

        // VERIFY
        assert(str == "qwertz");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("ciao");

        // VERIFY
        assert(str[2] == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("hello world");

        // VERIFY
        assert(str[0] == 'h');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str('\0');

        // VERIFY
        assert(str[0] == '\0');
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing subscript." << std::endl;

}