#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Concatenate two dynamic arrays.
// In your implementation you cannot use any STL function or class.
// Example:
// array_1 = {1, 2}, size_1 = 2
// array_2 = {2, 3, 4}, size_12 = 3
// Output: {1, 2, 2, 3, 4}.
//
// Answer these questions in the README file.
// Question 1: Why did we have to provide size_1, size_2 as an input?
// Question 2: How can we know the size of the output?
int *Concatenate(int *array_1, int size_1, int *array_2, int size_2){
        if (size_1 == 0 && size_2 == 0) {
        return nullptr;
    }
    int* concat= new int[size_1 +size_2]; //new array size
    //get all values from array 1
    for (int i=0; i<size_1; i++){
        concat[i]= array_1[i];
    }
    //get all values from array 2
    for (int i=0; i<size_2; i++){
        concat[size_1+i]= array_2[i];
    }
    return concat;
}






//-----------------------------------------------------------------------------
// Concatenate two vectors.
// In your implementation you cannot use any STL function or class other then
// vector.

// Example:
// vector_1 = {1, 2}
// vector_2 = {2, 3, 4}
// Output: {1, 2, 2, 3, 4}.
// Question 1: Why didn't we provide the sizes?
// Question 2: We have two functions with the name of Concatenate. Is this ok?
std::vector<int> Concatenate(std::vector<int> &vector_1, std::vector<int> &vector_2){
    std::vector<int> con;
    con.insert(con.end(),vector_1.begin(),vector_1.end());  //insert at the back
    con.insert(con.end(),vector_2.begin(), vector_2.end());
    return con;
}
