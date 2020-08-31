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
        String  str2("hello");

        // VERIFY
        assert(str < str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("MY name is Lorenzo");
        String  str2("my name is Lorenzo");

        // VERIFY
        assert(str < str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("012345678");
        String  str2("123456789");

        // VERIFY
        assert(str < str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
        String  str2;

        // VERIFY
	std::cout<<(str<str2)<<std::endl;
        assert((str < str2)==0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Qwerty");
        String  str2("qwertyu");

        // VERIFY
        assert(str < str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hell! World");
        String  str2("hello World");

        // VERIFY
        assert(str < str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("\tLorenzo\tToscano\n\n\n");
        String  str2("Lorenzo\tToscano");

        // VERIFY
        assert(!(str==str2));
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing lessThan." << std::endl;
}
