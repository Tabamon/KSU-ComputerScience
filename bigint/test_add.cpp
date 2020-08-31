// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;
      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //assert(1 == 2); //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.

    
    //Add test cases as needed.
    //1
    {
      bigint big1(9);
      bigint big2(1);
      bigint result;

      result = big1 + big2;
      assert(result==10);
    }
//2
    {
      bigint big1(9);
      bigint big2(9);
      bigint result;

      result = big1 + big2;
      assert(result==18);
    }
//3
    {
      bigint big1(10);
      bigint big2(1);
      bigint result;

      result = big1 + big2;
      assert(result==11);
    }    
//4    
    {
      bigint big1(50);
      bigint big2(49);
      bigint result;

      result = big1 + big2;
      assert(result==99);
    }
//5
    {
      bigint big1(99);
      bigint big2(1);
      bigint result;

      result = big1 + big2;
      assert(result==100);
    }
    //6
    {
      bigint big1(100);
      bigint big2(150);
      bigint result;

      result = big1 + big2;
      assert(result==250);
    }
//7

    {
      bigint big1(998);
      bigint big2(3);
      bigint result;

      result = big1 + big2;
      assert(result==1001);
    }
//8

    {
      bigint big1(1000);
      bigint big2(369);
      bigint result;

      result = big1 + big2;
      assert(result==1369);
    }
//9

    {
      bigint big1("2222");
      bigint big2("8888");
      bigint result;

      result = big1 + big2;
      assert(result==11110);
    }
//10
    {
      bigint big1("50123");
      bigint big2(987);
      bigint result;

      result = big1 + big2;
      assert(result==51110);
    }
//11
    {
      bigint big1("99999");
      bigint big2(1);
      bigint result;

      result = big1 + big2;
      assert(result==100000);
    }
//12
    {
      bigint big1("100001");
      bigint big2(19871);
      bigint result;

      result = big1 + big2;
      assert(result==119872);
    }
//13
    {
      bigint big1("100000");
      bigint big2(999999);
      bigint result;

      result = big1 + big2;
      assert(result==1099999);
    }
//14
    {
      bigint big1("1000000");
      bigint big2(123456);
      bigint result;

      result = big1 + big2;
      assert(result==1123456);
    }
//15
    {
      bigint big1("9900000");
      bigint big2(220000);
      bigint result;

      result = big1 + big2;
      assert(result=="10120000");
    }
//16
    {
      bigint big1("10120000");
      bigint big2("10120000");
      bigint result;

      result = big1 + big2;
      assert(result==20240000);
    }
//17
    {
      bigint big1("99999999");
      bigint big2(1);
      bigint result;

      result = big1 + big2;
      assert(result=="100000000");
    }
//18
    {
      bigint big1("987000000");
      bigint big2(30000000);
      bigint result;

      result = big1 + big2;
      assert(result=="1017000000");
    }
//#full_send
    {
      bigint big1("1000000000000000000000000000000000");
      bigint big2("1000000000000000000000000000012000");
      bigint result;

      result = big1 + big2;
      assert(result=="2000000000000000000000000000012000");
    }
    std::cout << "Done with testing addition." << std::endl;
}

