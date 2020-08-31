#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Kent State University");
        String  str2("Ke");

        // VERIFY
        //std::cerr<<str.findstr(0,str2)<<'\n';
        assert(str.findstr(0,str2) == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("123456789");
        String  str2("67");

        // VERIFY
        assert(str.findstr(0,str2) == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("asdfghjkl");
        String  str2("dfg");

        // VERIFY
        assert(str.findstr(1,str2) == 2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");
        String  str2("rt");



        // VERIFY
        assert(str.findstr(0,str2) == 3);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Lorenzo Toscano");
        String  str2("Lorenzo");

        // VERIFY
        assert(str.findstr(0,str2) == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Kent State University");
        String  str2("State");

        // VERIFY
        assert(str.findstr(4,str2) == 5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
        String  str2("State");

        // VERIFY
        assert(str.findstr(4,str2) == -1);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing findstring." << std::endl;
}