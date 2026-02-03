#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(k,test1){
    std::vector<int> vec = {1, 10, 5, 4, 8, 9};
    int k=3;
    std::vector<int> exp = {50,200,400,720};

    EXPECT_EQ(ProductOfKHighestNumbers(vec, k), exp);

    vec ={1, 10, 5, 4, 8, 9};
    k = 13;
    exp = {};

    EXPECT_EQ(ProductOfKHighestNumbers(vec, k), exp);
}
