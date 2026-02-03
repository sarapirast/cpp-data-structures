#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


  // // Creates a vector of the given size.
  // MyVector(int size);

  // // Copy constructor.
  MyVector::MyVector(): data_(nullptr), size_(0), error_(ErrorCode::kNoError) {}

  MyVector::~MyVector() {
    delete[] data_;
    data_ = nullptr;
  }


//from hw 2 q5
  void MyVector::push_back(int value){ 
    int* array1= new int[size_ + 1];
    for (int i = 0; i < size_; i++) {
        array1[i] = data_[i];
    }
    array1[size_] = value; //the last index of array gets the new element
    delete[] data_;
    data_= array1; //array contains address
    size_++;
    error_ = ErrorCode::kNoError;
}


  int MyVector::pop_back(){
    if (size_ == 0){
        error_= ErrorCode::kPopFromEmptyVector;
        return -1; //to leave
    } 
    int val = data_[size_ - 1]; 
    int *array1 = new int[size_ - 1];
    for (int i = 0; i < size_ - 1; i++) {
        array1[i] = data_[i];
    }
    delete[] data_;
    data_ = array1;
    size_--;
    error_ = ErrorCode::kNoError;
    return val; //popped value
}

  void MyVector::push_front(int value){
   int* array1= new int[size_ + 1]; //allocate memory
    array1[0] = value;
    for (int i = 0; i < size_; i++) {
        array1[i + 1] = data_[i];
    }
    delete[] data_;
    data_= array1;
    size_++;
    error_= ErrorCode::kNoError;
}


  int MyVector::pop_front(){
    if (size_ == 0) {
        error_ = ErrorCode::kPopFromEmptyVector;
        return -1;
    }
    int val= data_[0]; 
    int* array1 = new int[size_ - 1]; //allocate memory space
    for (int i = 1; i < size_; i++) {
        array1[i - 1] = data_[i];
    }
    delete[] data_;
    data_ = array1;
    size_--;
    error_ = ErrorCode::kNoError;
    return val;
}


  void MyVector::insert(int value, int index){
    if (index < -1 || index >= size_) { //if outside of array
        error_ = ErrorCode::kIndexError;
        return ;
    }
    int *array1 = new int[size_ + 1];
    if (index == -1) {
        array1[0] = value;
        for (int i = 0; i < size_; i++) { //before
            array1[i+1] = data_[i];
    }
    }
    else if (index >= 0 && index < size_) {
        for (int i = 0; i <= index; i++) {
            array1[i] = data_[i];
        }
        array1[index + 1] = value;
        for (int i = index + 1; i < size_; i++) {
            array1[i + 1] = data_[i];
        }
    }
    else if (index == size_) {
        for (int i = 0; i < size_; i++) {
            array1[i] = data_[i];
        }
        array1[size_] = value;
    }

    // else{
    //     for (int i = 0; i <= index; i++) { //before
    //         array1[i] = data_[i];
    //     }

    //     array1[index+1] = value;

    //     for (int i = index; i < size_; i++) { //after
    //         array1[i + 1] = data_[i];
    //     }
    // }
    delete[] data_;
    data_ = array1;
    size_++;
    error_ = ErrorCode::kNoError;
}

  int MyVector::at(int index){
    if (index < 0 || index >= size_){
        error_ = ErrorCode::kIndexError;
        return -1;
    }
    error_ = ErrorCode::kNoError;
    return data_[index]; //if no error the data at the index gets returned
  }

  int MyVector::find(int item){
    for (int i = 0; i < size_; i++) {
        if (data_[i] == item) {
            error_ = ErrorCode::kNoError;
            return i;
        }    
    }
    error_ = ErrorCode::kNotFound;
    return -1; //if not found
}

  ErrorCode MyVector::get_error() const{
    return error_;
  }

    int MyVector::size() const{
        return size_;
    }

  std::vector<int> MyVector::ConvertToStdVector(){
    std::vector<int> vect(data_, data_ + size_);
    return vect;
  }

