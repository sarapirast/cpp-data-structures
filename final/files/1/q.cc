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
//knapsack with backtracking?
void helper(std::vector<int> &nums, std::vector<std::vector<int>> &result, std::vector<int> &curResult, int limit){
// Check for leaf...
if (limit==0){
    result.push_back(curResult); //can't insert for set
    return;
}
// Generate the graph on the fly
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= limit) {
            curResult.push_back(nums[i]);
            helper(nums, result, curResult,limit-nums[i]);
            curResult.pop_back();

        }
    }
}


std::vector<std::vector<int>> findResource(std::vector<int> &tasks, int limit){
    std::vector<std::vector<int>> res;
    std::vector<int> x;
    if (limit == 0 || tasks.empty()) return res;
    helper(tasks,res,x,limit);
    for (auto &i : res)
        std::sort(i.begin(), i.end());
    std::set<std::vector<int>> result(res.begin(), res.end());
    return std::vector<std::vector<int>>(result.begin(), result.end());
}

//not sure how to implement backtracking, tried it and it didn't work
// for (int i = 0; i < nums.size(); i++) {
// // Avoid invalid children
// if (find(curResult.begin(), curResult.end(),
// nums[i]) != curResult.end()) {
// continue;
// }
// Update curResult
//curResult.push_back(nums[i]);
// Recursive DFS call
// Permute_aux(nums, result, curResult);
// Reset curResult
// curResult.pop_back();

