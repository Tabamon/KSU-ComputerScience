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
        std::cout<<"in char"<<'\n';
        String  str("qw");

        // VERIFY
        std::cout<<str<<'\n';
        assert(str == "qw");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("qwerty");
        //std::cout<<str<<'\n';
        // VERIFY
        assert(str == "qwerty");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("qwerty2\n");
        String str2("qwerty2\n");

        // VERIFY
        assert(str == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("12345678\n12345");

        // VERIFY
        assert(str == "12345678\n12345");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("\0");

        // VERIFY
        assert(str == "\0");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing charArray constructor." << std::endl;

}