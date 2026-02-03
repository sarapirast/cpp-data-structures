#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
  // A dynamic array to store the data.
//   int* data_;

//   // Store the size of the array here.
//   int size_;

//   // Set this value accordingly based on whether the last operation on the
//   // vector has error.
//   ErrorCode error_;

//need to use initializer bc of error? need to have it call the default constructor (stackoverflow)
MyVector::MyVector(): data_(nullptr), size_(0), error_(ErrorCode::kNoError){} //init

// Creates a vector of the given size. (need to allocate mem)
MyVector::MyVector(int size): size_(size), data_(new int[size]()), error_(ErrorCode::kNoError){}

// Copy constructor.
MyVector::MyVector(const MyVector& rhs): size_(rhs.size_), data_(new int[rhs.size_]()),error_(rhs.error_){
//need all elements
for (int i=0;i<size_;i++){
    data_[i]=rhs.data_[i]; //deep copy??
}
}

// Destructor.
// Should delete data and set it to nullptr. Also set size_ to 0.
  MyVector::~MyVector(){
    delete[] data_;
    data_ = nullptr;
    size_=0;
    error_ = ErrorCode::kNoError;

  }

 // Inserts the given value at the back of the vector.
 //need to allocate space for the new element
  void MyVector::push_back(int value){ 
        int* pushvec = new int[size_+1]; //new array to store original and pushed val, works even if size =0
        for (int i=0; i<size_;i++){ 
            pushvec[i] = data_[i];
        }
        delete[] data_;

        pushvec[size_]= value;

        data_ = pushvec;
        size_++;
        error_ = ErrorCode::kNoError;
        //delete[] pvec; //no
    
    }
 
 // Removes and returns a value from the backs of the vector.
  int MyVector::pop_back(){
    if (size_==0){
        error_ = ErrorCode::kPopFromEmptyVector;
        return -1;
    }
    int val = data_[size_-1];
    int* popvec = new int[size_-1];
    for (int i=0;i<size_-1;i++){
        popvec[i]=data_[i];
    }

    delete[] data_;

    data_= popvec;
    size_--;
    error_ = ErrorCode::kNoError;


    return val;
  }


// Inserts the given value at the front of the vector.
 void MyVector::push_front(int value){
    int* pushvec = new int[size_+1];
    pushvec[0]= value;
    for (int i=0; i<size_;i++){
        pushvec[i+1]=data_[i];
    }
    delete[] data_;

    data_ = pushvec;
    size_++;
    error_= ErrorCode::kNoError;
 }


 // Removes and returns a value from the front of the vector.
  int MyVector::pop_front(){
    if (size_==0){
        error_ = ErrorCode::kPopFromEmptyVector;
        return -1;
    }
    int val  = data_[0];
    int* popvec = new int[size_-1]; //same as pop_back
    for (int i=1;i<size_;i++){
        popvec[i-1]=data_[i];
    }

    delete[] data_;

    data_= popvec;
    size_--;
    error_ = ErrorCode::kNoError;


    return val;

  }


// If the given index is invalid, set the error code.
 // Inserts the given value after the given index.
  // 1. Create a new dynamic array
  // If the given index is -1, it inserts the item at the very beginning of the
  // vector.
  // 2. Copy from the old array until index
  // 3. insert value
  // 4. Copy the rest from the old array.
  // 5. DELETE the array.
  // 6. return the pointer inside the new dynamic array.

  void MyVector::insert(int value, int index){
    if (index < -1|| index>size_) {
        error_ = ErrorCode::kIndexError;
        return; //exit function
    }

    int* insvec = new int[size_+1];

    if (index == -1) {
        insvec[0] = value;
        for (int i = 0; i<size_; i++) {
            insvec[i + 1] = data_[i];
        }
    }
    else if (index == size_){
      for (int i = 0; i<size_; i++) {
            insvec[i] = data_[i];
      }
      insvec[size_] = value;
    }
    else {
        for (int i=0; i<=index;i++){
            insvec[i] = data_[i];
        }
        insvec[index]= value;
        for (int i=index; i<size_;i++){
            insvec[i+1]= data_[i];
        }
    }
    delete[] data_;

    data_ = insvec;
    size_++;
    error_ = ErrorCode::kNoError;

  }

 // Returns the item at the given index.
  int MyVector::at(int index){
    if (index<0 || index>=size_) {
        error_ = ErrorCode::kIndexError;
        return -1;
    }
    else {
        error_ = ErrorCode::kNoError;
        return data_[index];
    }
  }

 // Returns the first index of the given item in the vector. Returns -1 if not
  // found.
  int MyVector::find(int item){
    for (int i = 0; i< size_; i++) {
        if (data_[i] == item) {
            error_ = ErrorCode::kNoError;
            return i;
        }
    }
    //if not found
    error_ = ErrorCode::kNotFound;
    return -1;
}

// Returns the value of error_
  ErrorCode MyVector::get_error() const{return error_;}

  // Returns the value of size_
  int MyVector::size() const{return size_;}

  // Converts to std::vector. Used for testing.
  std::vector<int> MyVector::ConvertToStdVector(){
    std::vector<int> vec(size_);
    for (int i = 0; i<size_; i++) {
        vec[i] = data_[i];
    }

    return vec;

  }