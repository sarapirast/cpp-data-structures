#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


/////////Grader test/////////////
TEST(IsPrime, one) { 
  int determination = IsPrime(1);
  EXPECT_EQ(0, determination); 
}

TEST(IsPrime, NonPrimes) {

   int result = IsPrime(20);
  EXPECT_EQ(0, result);

  result = IsPrime(4);
  EXPECT_EQ(0, result);

  result = IsPrime(400);
  EXPECT_EQ(0, result);

  result = IsPrime(-1);
  EXPECT_EQ(0, result);
}
//////////////////////////////////////
/////////student test///////
TEST(IsPrime, Primes) {

   int result = IsPrime(29);
   EXPECT_EQ(1, result);

   result = IsPrime(401);
   EXPECT_EQ(1, result);

   result = IsPrime(2);
   EXPECT_EQ(1, result);
}

TEST(IsPrime, zero) {
   int result = IsPrime(0);
   EXPECT_EQ(0, result);
}