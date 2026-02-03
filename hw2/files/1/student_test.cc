#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(mapped, hello){
    std::string input = "hello";
    std::map<char, int> expected = {{'h',1},{'e',1},{'l',2},{'o',1}};
    EXPECT_EQ(CountCharacters(input),expected);
}

TEST(mapped, space){
    std::string input = " ";
    std::map<char, int> expected = {{' ',1}};
    EXPECT_EQ(CountCharacters(input),expected);
}


TEST(mapped, numbers){
    std::string input = "123123";
    std::map<char, int> expected = {{'1',2},{'2',2},{'3',2}};
    EXPECT_EQ(CountCharacters(input),expected);
}

TEST(mapped, empty){
    std::string input = "";
    std::map<char, int> expected = {};
    EXPECT_EQ(CountCharacters(input),expected);
}