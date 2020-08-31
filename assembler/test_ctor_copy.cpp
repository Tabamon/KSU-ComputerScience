//  Stack class test program
//
//  Tests: Copy Ctor
//

#include "stack.hpp"
#include "../string/string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> x;
        stack<int> x2(x);
        // VERIFY
        assert(x.empty());
        assert(x2.empty());

        stack<String> stringStack;
        stringStack.push("Hello");
        stack<String> stringStack2(stringStack);
        assert(stringStack2.pop()=="Hello");
        assert(stringStack2.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> stringStack;
        stringStack.push("Hello");
        stack<String> stringStack2(stringStack);
        assert(stringStack2.pop()=="Hello");
        assert(stringStack.pop()=="Hello");
        assert(stringStack2.empty());
        assert(stringStack.empty());
    }

    {   

        stack<String> firstStack;
        String testString("this is a test");

        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testString);
        }

        stack<String> secondStack(firstStack);

        for (unsigned i = 0; i<1000; i++){
            assert(secondStack.pop()==testString);
        }

    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy ctor." << std::endl;

}