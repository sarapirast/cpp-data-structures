#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(findnum,test1){
// {1, 1, 1},
// {1, 1, 1}
std::vector<std::vector<int>> grid = {{1,1,1},{1,1,1}};
std::pair<int, int> start = {0,0};
std::pair<int, int> end = {1,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),3);

grid = {{1,1,1}};
start = {0,0};
end = {0,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),1);


grid = {{1,0,1}};
start = {0,0};
end = {0,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),0);

grid = {{1,1,1},{1,0,1}};
start = {0,0};
end = {1,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),1);





}




TEST(findnum,test2){
// {1, 1, 1},
// {1, 1, 1}
std::vector<std::vector<int>> grid = {};
std::pair<int, int> start = {0,0};
std::pair<int, int> end = {1,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),0);

grid = {{1,1,1}};
start = {0,0};
end = {0,0};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),1);


grid = {{0,0,1,}};
start = {0,0};
end = {0,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),0);

grid = {{1,1,1},{1,0,1}};
start = {3,0};
end = {1,2};

EXPECT_EQ(FindNumberOfUniquePaths(grid,start,end),0);



}