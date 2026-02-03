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
// TODO: Implement the following class:
// A Max Heap that contains objects of type Student.
// We compare the students only based on their grade, not their names. That
// means the student with the highest grade should always be at the top of the
// heap.



  // Parameterized constructor: creates a max heap from the given input.
  StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input){
    ConvertToHeap(input);
  }

  // Returns the parent of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetParent(int i){
    int parent= GetParentIndex(i);
    return (parent== INT_MAX) ? Student("NO_NAME", INT_MIN) : data_[parent];
  }

  // Returns the left child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetLeft(int i){
     int left= GetLeftIndex(i);
     return (left== INT_MAX) ? Student("NO_NAME", INT_MIN) : data_[left];
  }

  // Returns the right child of a node given its index in the tree. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::GetRight(int i){int right= GetRightIndex(i);
    return (right== INT_MAX) ? Student("NO_NAME", INT_MIN) : data_[right];}

  // Returns the index of the parent of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetParentIndex(int i){
    return (i <= 0 || i >= size()) ? INT_MAX : (i - 1) / 2;
  }

  // Returns the index of the left child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLeftIndex(int i){
    int left= 2*i+ 1;
    return (left>= size()) ? INT_MAX: left;}

  // Returns the index of the right child of a node given its index in the tree.
  // Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetRightIndex(int i){
    int right= 2*i+ 2;
    return (right>= size()) ? INT_MAX: right;
  }

  // Returns the index of the largest child of a node given its index in the
  // tree. Returns INT_MAX if unsuccessful.
  int StudentMaxHeap::GetLargestChildIndex(int i){
    int left= GetLeftIndex(i);
    int right= GetRightIndex(i);
    if (left== INT_MAX) return INT_MAX;
    if (right== INT_MAX) return left;
    return (data_[left]> data_[right]) ? left:right;
  }

  // Returns the top of the heap. Returns
  // Student("NO_NAME", INT_MIN) if unsuccessful.
  Student StudentMaxHeap::top(){
    return (empty())? Student("NO_NAME", INT_MIN):data_[0];
  }

  // Adds a new Student to the heap.
  void StudentMaxHeap::push(const Student& student){
    data_.push_back(student);
    int i= size()-1;
    while (i>0) {
        int parent= (i-1)/2;
        if (data_[i]>data_[parent]) {
            std::swap(data_[i], data_[parent]);
            i= parent;
        } else{
            break;
        }
    }

  }

  // Removes the top. Returns
  // true if successful and false otherwise.
  bool StudentMaxHeap::pop(){
    if (empty()) return false;
    std::swap(data_[0], data_.back());
    data_.pop_back();
    if (!empty()){
      TrickleDown(0);
    }
    return true;
  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleUp(int i){
    int parent= GetParentIndex(i);
    while (i>0 && data_[i]>data_[parent]) {
        std::swap(data_[i], data_[parent]);
        i=parent;
        parent= GetParentIndex(i);
    }
  }

  // Performs trickle up. It should use the overloaded operators of the Student
  // class.
  void StudentMaxHeap::TrickleDown(int i){
    int large= GetLargestChildIndex(i);
    while (large!= INT_MAX && data_[large] > data_[i]) {
        std::swap(data_[i], data_[large]);
        i= large;
        large= GetLargestChildIndex(i);
    }
  }

  // Converts the given input into a max heap and stores that into data_.
  void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input){
    data_ = input;
    for (int i = size() / 2 - 1; i >= 0; --i) {
        TrickleDown(i);
    }
  }

//-----------------------------------------------------------------------------
// TODO: Implement this function:
// Sorts the given input vector of students in place. The sort is in ascending
// order based on the grades. Use heap sort!
void HeapSort(std::vector<Student>& input){
    StudentMaxHeap heap(input);
    input.clear();
    while (!heap.empty()) {
        input.push_back(heap.top());
        heap.pop();
    }
    std::reverse(input.begin(), input.end());
}