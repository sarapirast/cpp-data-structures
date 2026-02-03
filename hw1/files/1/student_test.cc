#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Reversefull,elements){
    std::vector<int> input = {1,2,3};
    std::vector<int> expected = {3,2,1};
    EXPECT_EQ(Reverse(input),expected);
}

TEST(Reverseempty,empty){
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(Reverse(input),expected);
}

TEST(Reverseone,one){
    std::vector<int> input = {1};
    std::vector<int> expected = {1};
    EXPECT_EQ(Reverse(input),expected);
}

TEST(Reversesame,same){
    std::vector<int> input = {1,1,1,1,1,1};
    std::vector<int> expected = {1,1,1,1,1,1};
    EXPECT_EQ(Reverse(input),expected);
}

TEST(PlusOne,elements){
    std::vector<int> input = {1,2,3};
    std::vector<int> expected = {1,2,4};
    EXPECT_EQ(PlusOne(input),expected);
}

TEST(PlusOne9mid,elements){
    std::vector<int> input = {1,9};
    std::vector<int> expected = {2,0};
    EXPECT_EQ(PlusOne(input),expected);
}

TEST(PlusOne9beg,elements){
    std::vector<int> input = {9,9,9};
    std::vector<int> expected = {1,0,0,0};
    EXPECT_EQ(PlusOne(input),expected);
}

TEST(PlusOneinv,elements){
    std::vector<int> input = {12};
    std::vector<int> expected = {-1};
    EXPECT_EQ(PlusOne(input),expected);
}