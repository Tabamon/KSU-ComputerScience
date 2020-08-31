#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================
std::ifstream in("test.txt");
int main ()
{

    {
        //------------------------------------------------------ ERROR??? FIX!!
        // SETUP FIXTURE
        
        String  str;
        char test[100];
        in >> str;
        in >> test;

        // VERIFY
        assert(test == str);
    }

    {
        //------------------------------------------------------ ERROR??? FIX!!
        // SETUP FIXTURE
        String  str;
        char test[100];
        in >> str;
        in >> test;

        // VERIFY
        assert(test == str);
    }

    {
        //------------------------------------------------------ ERROR??? FIX!!
        // SETUP FIXTURE
        String  str;
        char test[100];
        in >> str;
        in >> test;

        // VERIFY
        assert(test != str);
    }    

    // ADD ADDITIONAL TESTS AS NECESSARY
    std::cout << "Done testing input." << std::endl;

}