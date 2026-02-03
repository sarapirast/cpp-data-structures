#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid,
                            const std::pair<int, int> start,
                            const std::pair<int, int> end){
// if the side of grid is zero return 0
// if the zero at the {0,0}
// if zero at end, return 0
// if unequal vectors?
//if end out of bound === 0
int row = grid.empty()? 0: grid.size();
int col = grid.empty()? 0: grid[0].size();

if (start==end) return 1;
if (start.first<0 || start.first >= row) return 0;
if (start.second<0 || start.second >= col) return 0;
if (end.first<0 || end.first >= row) return 0;
if (end.second<0 || end.second >= col) return 0;

if (grid[start.first][start.second] == 0 || grid[end.first][end.second] == 0) return 0;



int side = FindNumberOfUniquePaths(grid, {start.first,start.second+1}, end); //pair go to next col
int down = FindNumberOfUniquePaths(grid, {start.first+1,start.second}, end); //go to next row

return (side + down);
}