#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(CountNumberOfSpaces, ThreeSpaces) {
  EXPECT_EQ(CountNumberOfSpaces("Hello World"), 1);
}

TEST(CountNumberOfSpaces, MultipleSpaces) {
  EXPECT_EQ(CountNumberOfSpaces("     "), 5);
}

TEST(CountNumberOfSpaces, zero) {
  EXPECT_EQ(CountNumberOfSpaces(""), 0);
}