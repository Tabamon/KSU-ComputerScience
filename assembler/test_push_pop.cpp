//  Stack class test program
//
//  Tests: push pop
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

        x.push(200);
        x.push(120);
        x.push(3);

        // VERIFY
        assert(x.pop()==3);
        assert(x.pop()==120);
        assert(x.pop()==200);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;

        x.push("Hello");
        x.push("World");
        x.push("!");

        // VERIFY
        assert(x.pop()=="!");
        assert(x.pop()=="World");
        assert(x.pop()=="Hello");
        assert(x.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;

        x.push("Long String");
        x.push("longer string");
        x.push("longest string");

        // VERIFY
        assert(x.pop()=="longest string");
        assert(x.pop()=="longer string");
        assert(x.top()=="Long String");
        assert(!x.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;

        x.push("This is the first string i push in this stack");
        x.push("this is the second string i push in this stack");
        x.push("I will push many more strings");
        x.push("  1");
        x.push("  2");
        x.push("  3");
        x.push("  4");

        // VERIFY
        assert(x.pop()=="  4");
        assert(x.pop()=="  3");
        assert(x.pop()=="  2");
        assert(x.pop()=="  1");
        assert(x.pop()=="I will push many more strings");
        assert(x.pop()=="this is the second string i push in this stack");
        x.pop();
        assert(x.empty());
    }

    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing push pop." << std::endl;

}