#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(rec, test1) {
    EXPECT_EQ(maxSubarraySumRecursive({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(maxSubarraySumRecursive({2}), 2);
    EXPECT_EQ(maxSubarraySumRecursive({5, 2, -1, 7, 8}), 21);
    EXPECT_EQ(maxSubarraySumRecursive({}), 0);
}

//-----------------------------------------------------------------------------
TEST(memo, test2) {
    EXPECT_EQ(maxSubarraySumMemoization({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(maxSubarraySumMemoization({2}), 2);
    EXPECT_EQ(maxSubarraySumMemoization({5, 2, -1, 7, 8}), 21);
    EXPECT_EQ(maxSubarraySumMemoization({}), 0);
}

//-----------------------------------------------------------------------------
TEST(tab, test3) {
    EXPECT_EQ(maxSubarraySumTabulation({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    EXPECT_EQ(maxSubarraySumTabulation({2}), 2);
    EXPECT_EQ(maxSubarraySumTabulation({5, 2, -1, 7, 8}), 21);
    EXPECT_EQ(maxSubarraySumTabulation({}), 0);
}