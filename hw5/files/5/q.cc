#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//From Dynamic programming lecture

int knapsack01(std::vector<int> &weights, std::vector<int> &values, int i,
               int capacity){

if (i==-1|| capacity==0) return 0;
if (weights[i]>capacity) return knapsack01(weights,values,i-1,capacity);
return std::max(knapsack01(weights,values,i-1,capacity),values[i]+knapsack01(weights,values,i-1,capacity-weights[i]));
}



//-----------------------------------------------------------------------------
// Implement the knapsack problem recursively using memoization.
// Hint: in q.cc file, write a helper function called knapsack01_MemoHelper,
// which takes an extra parameter called memo. The memo variable should be
// instantiated in knapsack01_Memo and passed to the helper function.
int knapsack01_Memo(std::vector<int> &weights, std::vector<int> &values, int i,int capacity){
std::map<std::pair<int,int>,int>memo;
if (i==-1|| capacity==0) return 0;
if (memo.count(std::make_pair(i,capacity))>0){ //check if in mem
    return memo[std::make_pair(i,capacity)]; //return mem
}
if (weights[i]>capacity){
    memo[std::make_pair(i,capacity)]=knapsack01_Memo(weights,values,i-1,capacity); //if can't fit go to next
    return memo[std::make_pair(i,capacity)];
}
memo[std::make_pair(i,capacity)]=std::max(knapsack01_Memo(weights,values,i-1,capacity),
values[i]+knapsack01_Memo(weights,values,i-1,capacity-weights[i])); //if fits take max of cur and next, add to mem

return memo[std::make_pair(i,capacity)];
}




//-----------------------------------------------------------------------------
// Implement the knapsack problem recursively using tabulation.
// This function should not be recursive.
int knapsack01_Table(std::vector<int> &weights, std::vector<int> &values, int i,int capacity){
std::vector<std::vector<int>>tab(values.size()+1,std::vector<int>(capacity+1,0)); //botttom up method
for (int i=0;i<=weights.size();i++){
    for (int w=0;w<=capacity;w++){
        if (i== 0||w== 0){
            tab[i][w]= 0;
        }
        else if (weights[i-1] > w){
            tab[i][w]= tab[i-1][w]; 
        }
        else {
            tab[i][w]= std::max(values[i-1] + tab[i-1][w-weights[i-1]],tab[i-1][w]);
        }
    }
}
return tab[values.size()][capacity];
}
