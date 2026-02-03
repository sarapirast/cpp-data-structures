#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(Fib,test1 ) {

  EXPECT_EQ(Fibonacci(0), 1);
  EXPECT_EQ(Fibonacci(1), 1);
  EXPECT_EQ(Fibonacci(2), 2);
  EXPECT_EQ(Fibonacci(3), 3);
  EXPECT_EQ(Fibonacci(4), 5);
  EXPECT_EQ(Fibonacci(5), 8);
}