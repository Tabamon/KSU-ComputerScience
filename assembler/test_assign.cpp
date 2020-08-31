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

        stack<int> x2 = x;

        //std::cout<<"test"<<std::endl;

        // VERIFY
        assert(x.pop()==3);
        assert(x.pop()==120);
        assert(x.pop()==200);

        assert(x2.pop()==3);
        assert(x2.pop()==120);
        assert(x2.pop()==200);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> x;
        stack<String> x2;
        
        //std::cout<<"test"<<std::endl;

        x.push("Hello");
        x.push("World");
        x.push("!");

        x2 = x;

        // VERIFY
        assert(x2.pop()=="!");
        assert(x2.pop()=="World");
        assert(x2.pop()=="Hello");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> firstStack;
        stack<String> secondStack;
        
        //std::cout<<"test"<<std::endl;

        firstStack.push("Hello");
        firstStack.push("World");
        firstStack.push("!");

        secondStack = firstStack;

        // VERIFY
        assert(firstStack.top() == secondStack.top());
        firstStack.pop();
        assert(firstStack.top()!=secondStack.top());
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> firstStack;
        stack<String> secondStack;
        
        //std::cout<<"test"<<std::endl;

        firstStack.push("Hello");
        firstStack.push("World");
        firstStack.push("!");

        firstStack = secondStack;

        // VERIFY
        assert(firstStack.empty());
        assert(secondStack.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String> firstStack;
        stack<String> secondStack;
        
        String testStr("this is a test string designed for this test!");

        //std::cout<<"test"<<std::endl;
        for (unsigned i = 0; i<1000; i++){
            firstStack.push(testStr);
        }
        secondStack = firstStack;

        // VERIFY
        for (unsigned i = 0; i<1000; i++){
            assert(secondStack.pop()=="this is a test string designed for this test!");
        }
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing assign." << std::endl;

}