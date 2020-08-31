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

        // VERIFY
        assert(str.findch(0,'K') == -1);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Kent State University");

        // VERIFY
        assert(str.findch(0,'K') == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("123456789");

        // VERIFY
        assert(str.findch(0,'2') == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("asdfghjkl");

        // VERIFY
        assert(str.findch(1,'f') == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");

        // VERIFY
        assert(str.findch(0,'t') == 4);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Lorenzo Toscano");

        // VERIFY
        //std::cout << str.findch(3,'o') << std::endl;
        assert(str.findch(3,'o') == 6);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Kent State University");

        // VERIFY
        assert(str.findch(4,'z') == -1);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing findstring." << std::endl;
}