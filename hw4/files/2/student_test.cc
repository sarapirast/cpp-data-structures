#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(convert, test1) {
    std::vector<int> data = {};
    ConvertToMinHeap(data);
    EXPECT_EQ(data, std::vector<int>{} );
}


TEST(convert, test2) {
    std::vector<int> data = {10};
    ConvertToMinHeap(data);
    std::vector<int> res = {10};
    EXPECT_EQ(data, res);
}


TEST(convert, test3) {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    ConvertToMinHeap(data);
    EXPECT_EQ(data, std::vector<int>({1, 3, 5, 7, 9, 11}));
}


TEST(convert, test4) {
    std::vector<int> data = {20,15,30,5,10,25,35};
    ConvertToMinHeap(data);
    EXPECT_EQ(data[0], 5);
    EXPECT_TRUE(IsMinHeap(data));
}


TEST(convert, test5) {
    std::vector<int> data = {10,10,10};
    ConvertToMinHeap(data);
    EXPECT_EQ(data[0],10); 
    EXPECT_TRUE(IsMinHeap(data));
}


TEST(convert, test6) {
    std::vector<int> data = {20,10};
    ConvertToMinHeap(data);
    EXPECT_EQ(data, std::vector<int>({10,20}));
}


TEST(convert, test7) {
    std::vector<int> data = {-1,-5,-3,-10};
    ConvertToMinHeap(data);
    EXPECT_EQ(data[0],-10);
    EXPECT_TRUE(IsMinHeap(data));
}