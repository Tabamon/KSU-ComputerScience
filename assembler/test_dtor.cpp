//  Stack class test program
//
//  Tests: XXX
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
        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);
        x.push(5);
        x.pop();
        x.pop();
        // VERIFY
            //nothing to verify here
    }

    {   

        stack<String> firstStack;
        String testString("this is a test");

        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testString);
        }
        firstStack.pop();
    }

    {   

        stack<String> firstStack;
        String testString("this is a test");

        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testString);
        }

        stack<String> secondStack = firstStack;

        firstStack.pop();
        secondStack.pop();
        secondStack.push(testString);
    }

    {
        String test("123");
        stack<String> firstStack;
    }

    {   

        stack<String> firstStack;
        String testString("this is a test");

        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testString);
        }

        stack<String> secondStack(firstStack);

        firstStack.pop();
        secondStack.pop();
        secondStack.push(testString);
    }

    {   

        stack<String> firstStack;
        String testString("this is a test");

        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testString);
        }

        stack<String> secondStack(firstStack);

        firstStack.pop();
        secondStack.pop();

        firstStack.swap(secondStack);

    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing destructor." << std::endl;

}