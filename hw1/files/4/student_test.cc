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
TEST(Flatten3DVector, one) {
  std::vector<std::vector<std::vector<int>>> in = {{{1}}};
  auto out = Flatten3DVector(in);
  std::vector<int> expected = {1};
  EXPECT_EQ(out, expected);
}
