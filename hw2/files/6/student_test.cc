#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(setdiff, test1){ 
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {4, 5, 6};
    std::set<int> output = setDifference(set1, set2);
    std::set<int> expected = {1, 2, 3};
    EXPECT_EQ(output, expected);
}


TEST(setdiff, onesame){
    std::set<int> set1 = {1};
    std::set<int> set2 = {1};
    std::set<int> output = setDifference(set1, set2);
    std::set<int> expected = {};
    EXPECT_EQ(output, expected);
}

TEST(setdiff, one){
    std::set<int> set1 = {1};
    std::set<int> set2 = {4};
    std::set<int> output = setDifference(set1, set2);
    std::set<int> expected = {1};
    EXPECT_EQ(output, expected);
}

TEST(setdiff, emp2){
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {};
    std::set<int> output = setDifference(set1, set2);
    std::set<int> expected = {1, 2, 3};
    EXPECT_EQ(output, expected);
}

TEST(setdiff, emp1){
    std::set<int> set1 = {};
    std::set<int> set2 = {4, 5, 6};
    std::set<int> output = setDifference(set1, set2);
    std::set<int> expected = {};
    EXPECT_EQ(output, expected);
}

TEST(disjoint, test1){
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {4, 5, 6};

    bool output = areDisjoint(set1, set2);
    bool expected = true;
    EXPECT_EQ(output, expected);
}


TEST(disjoint, test2){
    std::set<int> set1 = {};
    std::set<int> set2 = {4, 5, 6};

    bool output = areDisjoint(set1, set2);
    bool expected = true;
    EXPECT_EQ(output, expected);
}


TEST(disjoint, test3){
    std::set<int> set1 = {};
    std::set<int> set2 = {};

    bool output = areDisjoint(set1, set2);
    bool expected = true;
    EXPECT_EQ(output, expected);
}

TEST(disjoint, test4){
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {1, 4, 5};

    bool output = areDisjoint(set1, set2);
    bool expected = false;
    EXPECT_EQ(output, expected);
}