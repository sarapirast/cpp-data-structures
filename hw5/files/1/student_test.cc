#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(HikerPathTest, SimpleMaze) {
  vector<vector<int>> maze = {//
                              {0, 0, 0, 1},
                              {0, 1, 0, 1},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0}};

  vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
                                      {2, 2}, {2, 3}, {3, 3}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}