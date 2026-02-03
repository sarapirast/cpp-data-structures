#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Function to add an element to the back of the array. Updates both array and size.
void push_back(int *&array, int &size, int element){
 
 //array is pointer reference? ref is a pointer

//pointer an be called by array 

 //need to change size so it has to be a new array?
 //need more memory since different size 
 //array has static mem

    int* array1 = new int[size+1];
    for (int i=0; i< size; i++){
        array1[i] = array[i];
    }
    array1[size] = element; //the last index of array gets the new element
    delete[] array;
    array = array1; //array contains address
    size++; 
    

  
    }

// Function to remove the last element from the array. Updates both array and
// size.
// No operations if array is empty.
void pop_back(int *&array, int &size){//same as prev but opposite
    if (size == 0)
        return;    
    int *array1 = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        array1[i] = array[i];
    }
    delete[] array;
    array = array1;
    size--;
}


void insert(int *&array, int &size, int element, int index){
    if (index < 0 || index > size) { //if outside of arra
        return;
}
    int *array1 = new int[size + 1];
    for (int i = 0; i < index; i++) { //before
       array1[i] = array[i];
    }
    array1[index] = element;
    for (int i = index; i < size; i++) { //after
        array1[i + 1] = array[i];
    }
    delete[] array;
    array = array1;
    size++;
}

int erase(int *&array, int &size, int index){
    if (index < 0 || index >= size) {
        return -1;
    }
    int *array1 = new int[size - 1];
    for (int i = 0; i < index; i++) { //before
        array1[i] = array[i];
    }
    for (int i = index + 1; i < size; i++) {
        array1[i - 1] = array[i];
    }
    delete[] array;
    array = array1;

    size--;

    return 0;
}


int find(const int *array, int size, int element){
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }    
    }
    return -1; //if not found
}

