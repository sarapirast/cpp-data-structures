#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
bool CanBecome(const std::string &s, const std::string &goal){

if (s.length()==0 && goal.length()==0)
    return true;
std::string temp = s;
char c;

if (s.length() != goal.length()){
    return false;
}
for (int i=0;i<s.length();i++){
    c = temp[0];
    temp = temp.substr(1) + c;
    if (temp == goal)
        return true;   
}
return false;
 
}
//subtr and loop causes O(n^2)