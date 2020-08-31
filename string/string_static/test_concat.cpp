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
        String  str2(" Toscano");

        // TEST
        String result = str+str2;

        // VERIFY
        assert(str    == "MY name is Lorenzo");
        //std::cout << result << std::endl;
        assert(result == "MY name is Lorenzo Toscano");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("1234567890");
        String  str2("1234567890");

        // TEST
        String result = str+str2;

        // VERIFY
        assert(str    == "1234567890");
        assert(result == "12345678901234567890");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('a');
        String  str2('b');

        // TEST
        String result = str+str2;

        // VERIFY
        assert(str    == "a");
        assert(result == "ab");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("qwerty");
        String  str2("qwerty");

        // TEST
        String result = str+str2;
        str += str2;
        String result2 = str2+"qwerty";
        String result3 = "qwerty"+str2;

        //std::cout<<result2;

        // VERIFY
        assert(str == "qwertyqwerty");
        assert(result == "qwertyqwerty");
        assert(result2 == "qwertyqwerty");
        assert(result3 == "qwertyqwerty");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hello World");
        String  str2('!');

        // TEST
        String result = str+str2;

        // VERIFY
        assert(str    == "Hello World");
        assert(result == "Hello World!");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("my name is \nLorenzo\tToscano");
        String str2('\n');

        // TEST
        String result = str+str2;
        str += str2;

        // VERIFY
        assert(str    == "my name is \nLorenzo\tToscano\n");
        assert(result == "my name is \nLorenzo\tToscano\n");
        assert(result == str);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing concat." << std::endl;
}
