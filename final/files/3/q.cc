#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int BFS(std::vector<std::vector<char>> &grid, int rootx, int rooty, int tx, int ty, int row, int col) {
    //similar to hw
    std::vector<std::vector<int>> dist(row, std::vector<int>(col,-1));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> directions = {{0, 1},{1, 0},{0, -1},{-1, 0}};    
    q.push({rootx,rooty});
    dist[rootx][rooty]=0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < directions.size(); ++i){
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            if (nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] != '1' && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                    if (nx == tx && ny == ty) {
                        return dist[nx][ny];
                    }      
                q.push({nx, ny});
            }
        }
    }

    return -1;
}



int fastestToTarget(std::vector<std::vector<char>> &grid){
    //two bfs cycles? me one root, friend other root, find the shortes path for each?
    if (grid.empty() || grid[0].empty()) return -1;
    int row=grid.size();
    int col= grid.empty()? 0 :grid[0].size();
    int y1=-1,y2=-1,m1=-1,m2=-1,t1=-1,t2=-1;
    for (int i=0; i<row;i++){
        for (int j=0; j<col;j++){
            if (grid[i][j]=='y'){
                m1= i;
                m2= j;
            }
            else if (grid[i][j]=='f'){
                y1= i;
                y2= j;
            }
            else if (grid[i][j]=='t'){
                t1= i;
                t2= j;
            }

        }
    }
    if (y1==-1||y2==-1||m1==-1||m2==-1||t1==-1||t2==-1) return -1;
    int md = BFS(grid, m1, m2, t1, t2,row,col);
    int fd = BFS(grid, y1, y2, t1, t2,row, col);

    if (md==-1 && fd==-1) return -1;
    if (fd == -1 && md != -1) return 1;
    if (md == -1 && fd != -1) return 2;
    if (md < fd) return 1;
    if (fd < md) return 2;
    if (fd == md )return 3;
}
