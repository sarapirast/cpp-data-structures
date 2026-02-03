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


std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k){
 if (input.size() < k) return {};
 std::vector<int> prod;
 for (size_t i=0; i<=input.size()-k;i++){
    std::vector<int> vec(input.begin(), input.begin() + i + k);
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    int p = 1;
    for (int j = 0; j < k; j++) {
        p *= vec[j];
    }
    prod.push_back(p);
 }
 return prod;
}
