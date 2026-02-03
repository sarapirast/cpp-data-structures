#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Function declarations for set operations

// Function to compute the set difference (elements present in set1 but not in
// set2)
std::set<int> setDifference(const std::set<int> &set1, const std::set<int> &set2){
    std::set<int>c;
    for (auto i : set1) {
        if (set2.find(i) == set2.end()) {
            c.insert(i);
        }
    }
    return c;
}

bool areDisjoint(const std::set<int> &set1, const std::set<int> &set2) {
    for (auto i : set1) {
        if (set2.find(i) != set2.end()) {
            return false;
        }
    }
    return true;
}
