#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_map>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


//Dynamic programming lecture
// Recursive solution
int RecursiveHelper(const std::vector<int> &nums, int i){
    if (i==0){
        return nums[0];
    } 
    else {
        return std::max(RecursiveHelper(nums,i-1)+nums[i],nums[i]);
    }
}

int maxSubarraySumRecursive(const std::vector<int> &nums){
    if (nums.empty()) return 0;
    std::vector<int>sum;
    for (int i=0;i<nums.size();i++){
        sum.push_back(RecursiveHelper(nums,i));
    }
    return *std::max_element(
    sum.begin(),sum.end());
}



// Recursive solution with memoization

int memohelper(const std::vector<int> &input, int i){
    std::unordered_map<int, int> memo;
    if (i==0){
        return input[0];
    }
    else {
        if (memo.count(i)>0){
            return memo[i];
        }
        else {
            memo[i] = std::max(memohelper(input,i-1)+input[i],input[i]);
            return memo[i];
        }
    }
}


int maxSubarraySumMemoization(const std::vector<int> &nums){
    if (nums.empty()) return 0;
    std::vector<int>sum;
    for (int i=0;i<nums.size();i++){
        sum.push_back(memohelper(nums,i));
    }
    return *std::max_element(
    sum.begin(),sum.end());
}

// Tabulation (bottom-up) approach
int maxSubarraySumTabulation(const std::vector<int> &nums){
    if (nums.empty()) return 0;
    std::vector<int>tab(nums.size());
    tab[0]=nums[0];
    for (int i=1;i<nums.size();i++){
        tab[i]=std::max(tab[i-1]+nums[i],nums[i]);
    }
    auto max= std::max_element(tab.begin(),tab.end());
    return *max;   
}
