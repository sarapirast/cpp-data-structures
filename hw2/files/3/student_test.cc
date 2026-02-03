#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(swappoint, numbers){
    float input1 = 2.4;
    float input2 = 1.5;
    SwapByPointer(&input1,&input2);
    EXPECT_FLOAT_EQ(input2,2.4);
    EXPECT_FLOAT_EQ(input1,1.5);
}


TEST(swapref, numbers){
    float input1 = 2.4;
    float input2 = 1.5;
    SwapByReference(input1,input2);
    EXPECT_FLOAT_EQ(input2,2.4);
    EXPECT_FLOAT_EQ(input1,1.5);
}

TEST(swappoint, zero){
    float input1 = 0.0;
    float input2 = 0.0;
    SwapByPointer(&input1,&input2);
    EXPECT_FLOAT_EQ(input2,0.0);
    EXPECT_FLOAT_EQ(input1,0.0);
}


TEST(swapref, zero){
    float input1 = 0.0;
    float input2 = 0.0;
    SwapByReference(input1,input2);
    EXPECT_FLOAT_EQ(input2,0.0);
    EXPECT_FLOAT_EQ(input1,0.0);
}



TEST(swappoint, neg ){
    float input1 = -10.0;
    float input2 = 20.0;
    SwapByPointer(&input1,&input2);
    EXPECT_FLOAT_EQ(input2,-10.0);
    EXPECT_FLOAT_EQ(input1,20.0);
}


TEST(swapref, neg){
    float input1 = -10.0;
    float input2 = 20.0;
    SwapByReference(input1,input2);
    EXPECT_FLOAT_EQ(input2,-10.0);
    EXPECT_FLOAT_EQ(input1,20.0);
}



TEST(swappoint, big ){
    float input1 = 1000000.0;
    float input2 = 20.0;
    SwapByPointer(&input1,&input2);
    EXPECT_FLOAT_EQ(input2,1000000.0);
    EXPECT_FLOAT_EQ(input1,20.0);
}


TEST(swapref, big){
    float input1 = -1000000.0;
    float input2 = 20.0;
    SwapByReference(input1,input2);
    EXPECT_FLOAT_EQ(input2,-1000000.0);
    EXPECT_FLOAT_EQ(input1,20.0);
}
