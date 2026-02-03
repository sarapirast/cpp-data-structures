#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze){
//lecture 7
if (maze.empty() || maze[0].empty()) return {{-1,-1}};
int row= maze.size();
int col= maze[0].size();

std::vector<std::pair<int,int>> dir= {{0,1},{1,0},{0,-1},{-1,0}}; //1. Right (Highest precedence),down.left,up (lowest precedence)
std::vector<std::vector<int>> result;
std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
std::queue<std::vector<std::vector<int>>> q;

if (maze[0][0]==0){
    q.push({{0,0}});
    visited[0][0]= true;
}

while (q.empty()== false){
    std::vector<std::vector<int>> curp= q.front();
    q.pop();
    int x= curp.back()[0];
    int y= curp.back()[1];

    if (x== row-1&& y== col-1) return curp;
    for (size_t i=0; i<dir.size(); i++){
        std::pair<int, int> dirs = dir[i];
        int x2=x+dirs.first;
        int y2=y+dirs.second;

        if (x2>=0 && x2<row && y2>=0 && y2<col && maze[x2][y2]== 0 && !visited[x2][y2]){    
            visited[x2][y2]= true;
            std::vector<std::vector<int>> np = curp;
            np.push_back({x2, y2});
            q.push(np);
}
}   
}
return {{-1,-1}};
}