#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

template <class T>
void PrintCollection(T& input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
TEST(ClimbStairs, Test1) {
  EXPECT_EQ(ClimbStairs(3), 4);
  EXPECT_EQ(ClimbStairs(0), 0);
  EXPECT_EQ(ClimbStairs(1), 1);
  EXPECT_EQ(ClimbStairs(2), 2);
}