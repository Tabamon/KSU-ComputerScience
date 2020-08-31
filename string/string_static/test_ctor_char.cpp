#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('/');

        // VERIFY
        assert(str == '/');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('Q');
        String str2('Q');

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('|');

        // VERIFY
        assert(str == '|');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('2');

        // VERIFY
        assert(str == '2');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing char constructor." << std::endl;

}

