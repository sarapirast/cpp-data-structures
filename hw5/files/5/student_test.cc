#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(knap1,empty){
    std::vector<int>weights= {};
    std::vector<int>values= {};
    int capacity=5;
    EXPECT_EQ(knapsack01(weights,values,-1,capacity),0);
}



TEST(knap1,zero) {
    std::vector<int>weights={6};
    std::vector<int>values={10};
    int capacity=5;
    EXPECT_EQ(knapsack01(weights,values,0,capacity),0);
}



TEST(knapmem, test1) {
    std::vector<int>weights={1,2,3};
    std::vector<int>values={10,20,30};
    int capacity= 5;
    
    EXPECT_EQ(knapsack01_Memo(weights,values,weights.size()-1,capacity),50);
}


TEST(knapmem,empty) {
    std::vector<int>weights={};
    std::vector<int> values={};
    int capacity=5;
    EXPECT_EQ(knapsack01_Memo(weights,values,-1,capacity),0);
}


TEST(knapmem,test2){
    std::vector<int>weights={5};
    std::vector<int>values={10};
    int capacity= 5;
    EXPECT_EQ(knapsack01_Memo(weights,values,0,capacity),10);
}


TEST(knapmem,test3){
    std::vector<int>weights={6};
    std::vector<int>values={10};
    int capacity=5;
    EXPECT_EQ(knapsack01_Memo(weights,values,0,capacity),0);
}




TEST(knaptab, test1){
    std::vector<int>weights= {1,2,3};
    std::vector<int>values= {10,20,30};
    int capacity=5;
    
    EXPECT_EQ(knapsack01_Table(weights,values,weights.size()-1,capacity),50);
}

TEST(knaptab, test2) {
    std::vector<int>weights= {};
    std::vector<int>values= {};
    int capacity= 5;

    EXPECT_EQ(knapsack01_Table(weights,values,0,capacity),0);
}

TEST(knaptab, test3) {
    std::vector<int>weights= {5};
    std::vector<int>values= {10};
    int capacity= 5;

    EXPECT_EQ(knapsack01_Table(weights,values,weights.size()-1,capacity),10);
}