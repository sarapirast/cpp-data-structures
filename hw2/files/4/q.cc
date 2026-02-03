#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
void UniqueVectorNotBySet(std::vector<int> &input){
    for (int i = 0; i < input.size(); i++) {
   //     for (int j = input.size()-1; j > 0; j--) { using erase means can't use j = input.size since the size changes
        for (int j= i+1; j<input.size();){
            if (input[i]==input[j]){
                input.erase(input.begin() + j); //erase needs iterator
            }
            else ++j; //so removing wont impact
        }
        }
    }


void UniqueVectorBySet(std::vector<int> &input){
    std::set<int>c(input.begin(), input.end());
    //set only takes unique elements so

    input.clear();

    input.insert(input.begin(),c.begin(),c.end()); //needs iterator input.begin()
}


std::vector<int> IntersectVectors(const std::vector<int> &input1,const std::vector<int> &input2){
    std::set<int> c; //so if duplicate it won't count
    std::set<int> in1(input1.begin(),input1.end());
    std::set<int> in2(input2.begin(),input2.end()); 


    for (auto i: in1){
        //if element of in1 found for in2
            if (in2.find(i) != in2.end()) //find function reutrns  iterator.end if not found, so making sure it is found here
            c.insert(i);
        }
  

    return std::vector<int>(c.begin(), c.end());
    
        }



std::set<int> DiffVectors(const std::vector<int> &input1, const std::vector<int> &input2){
    std::vector<int>c(IntersectVectors(input1, input2));
    std::vector<int>in1;
    for (auto i:input1){
        bool cont = 0;
        for (auto j : c) { //if in intersect we dont want it
            if (i == j) {
                cont =1;
                break;
        }
    }
    if (!cont)
        in1.push_back(i);
    }
return std::set<int>(in1.begin(), in1.end());
}