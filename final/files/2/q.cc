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
void PermuteII_aux(const std::vector<int> &nums,

    std::vector<std::vector<int>> &result,
    std::vector<int> &curResult,
    std::vector<bool> &used) {

    // If we get to a leaf, we save the path in result and return return.
    if (curResult.size() == nums.size()) {
    result.push_back(curResult);
    return;
    }
    for (int i = 0; i < nums.size(); i++) {
    if (used[i]) {
    continue;
    }
    // Avoid duplicates
    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
    continue;
    }
    if (!curResult.empty() && curResult.back() == nums[i]) {
        continue;
    }
    used[i] = true;
    curResult.push_back(nums[i]);
    PermuteII_aux(nums, result, curResult, used);
    curResult.pop_back();
    used[i] = false;
    }
}



std::vector<std::vector<int>>MovieTheaterAssignment(const std::vector<int> &students){
    //simialr to the chess game in the backtracking lecture? also example 2 with finding all the permutations
    std::vector<std::vector<int>> result;
std::vector<bool> used(students.size(), false);
std::vector<int> curResult;
// std::vector<int> s = students;
// std::sort(s.begin(), s.end());
PermuteII_aux(students, result, curResult, used);
return result;

}