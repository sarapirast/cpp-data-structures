#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(noset, mult){
    std::vector<int> input = {1,2,3,3,2};
    UniqueVectorNotBySet(input);
    std::vector<int> output = {1,2,3};
    EXPECT_EQ(input,output);
}

TEST(noset, one){
    std::vector<int> input = {1};
    UniqueVectorNotBySet(input);
    std::vector<int> output = {1};
    EXPECT_EQ(input,output);
}

TEST(noset, none){
    std::vector<int> input = {};
    UniqueVectorNotBySet(input);
    std::vector<int> output = {};
    EXPECT_EQ(input,output);
}

TEST(noset, neg){
    std::vector<int> input = {1,-2,-2,2,3,4,5,5,55};
    UniqueVectorNotBySet(input);
    std::vector<int> output = {1,-2,2,3,4,5,55};
    EXPECT_EQ(input,output);
}





TEST(wset, mult){
    std::vector<int> input = {1,2,3,3,2};
    UniqueVectorBySet(input);
    std::vector<int> output = {1,2,3};
    EXPECT_EQ(input,output);
}

TEST(wset, one){
    std::vector<int> input = {1};
    UniqueVectorBySet(input);
    std::vector<int> output = {1};
    EXPECT_EQ(input,output);
}

TEST(wset, none){
    std::vector<int> input = {};
    UniqueVectorBySet(input);
    std::vector<int> output = {};
    EXPECT_EQ(input,output);
}

TEST(wset, neg){
    std::vector<int> input = {1,-2,-2,2,3,4,5,5,55};
    UniqueVectorBySet(input);
    std::vector<int> output = {-2,1,2,3,4,5,55}; //set puts it in order
    EXPECT_EQ(input,output);
}


TEST(inters, reg){
    std::vector<int> input1 = {1,-2,-2,2,3,4,5};
    std::vector<int> input2 = {1,-2,3};
    std::vector<int> input = IntersectVectors(input1,input2);
    std::vector<int> output = {-2,1,3}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(inters, emp){
    std::vector<int> input1 = {};
    std::vector<int> input2 = {1,-2,3};
    std::vector<int> input = IntersectVectors(input1,input2);
    std::vector<int> output = {}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(inters, one){
    std::vector<int> input1 = {1};
    std::vector<int> input2 = {2};
    std::vector<int> input = IntersectVectors(input1,input2);
    std::vector<int> output = {}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(inters, onesame){
    std::vector<int> input1 = {1};
    std::vector<int> input2 = {1};
    std::vector<int> input = IntersectVectors(input1,input2);
    std::vector<int> output = {1}; //set puts it in order
    EXPECT_EQ(input,output);
}



TEST(diff, onesame){
    std::vector<int> input1 = {1};
    std::vector<int> input2 = {1};
    std::set<int> input = DiffVectors(input1,input2);
    std::set<int> output = {}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(diff, one){
    std::vector<int> input1 = {1};
    std::vector<int> input2 = {2};
    std::set<int> input = DiffVectors(input1,input2);
    std::set<int> output = {1}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(diff, emp2){
    std::vector<int> input1 = {1,2,3,4};
    std::vector<int> input2 = {};
    std::set<int> input = DiffVectors(input1,input2);
    std::set<int> output = {1,2,3,4}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(diff, emp1){
    std::vector<int> input1 = {};
    std::vector<int> input2 = {1,2,3,4};
    std::set<int> input = DiffVectors(input1,input2);
    std::set<int> output = {}; //set puts it in order
    EXPECT_EQ(input,output);
}

TEST(diff, neg){
    std::vector<int> input1 = {1,2,3,4,5,6,-1};
    std::vector<int> input2 = {1,2,3,4};
    std::set<int> input = DiffVectors(input1,input2);
    std::set<int> output = {-1,5,6}; //set puts it in order
    EXPECT_EQ(input,output);
}