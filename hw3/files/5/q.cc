#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
//  Given an expression string, find if the input has valid brackets (i.e. { }
  //  or [ ] or ( ) ).
  // An input expression is valid if:
  // Open brackets are closed by the same type of brackets. Open brackets must
  // be closed in the correct order. An empty string is also considered valid.
  // You should only check for the validity of brackets based on the above
  // rules, i.e. ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’, not the rest of the expression.
  // Example 1: Input: "(a+b)" Output: true
  // Example 2: Input: "(a+b)[c*d]{5g+h}" Output: true
  // Example 3: Input: "(a+b]" Output: false
  // Example 4: Input: "(7h+[5c)+7]" Output: false
  // Example 5: Input: "{2k+[5j]}" Output: true
  // Example 6: Input: "{2k++[5--*j]}" Output: true
  bool CPPLib::CheckValidExpression(const std::string& input){
    if (input.length()==0){return true;}
    int b1 = 0; //(
    int b2 = 0; //[
    int b3 = 0; //}

    char lasto = '\0'; //null char
    for (auto i : input) {
        if (i == '(') {
            b1++;
            lasto = '(';
        }
        else if (i == '[') {
            b2++;
            lasto = '[';
        }
        else if (i == '{') {
            b3++;
            lasto = '{';
        } 
        else if (i == ')') {
            if (b1 == 0 || lasto != '(') {return false;}
            b1--;
            if (b2 > 0){
                lasto = '[';
            }
            else if (b3 > 0){
                lasto = '{';
            }
            else{
                lasto = '\0';
            }
        }
        else if (i == ']') {
            if (b2 == 0 || lasto != '[') return false;
            b2--;
            if (b1 > 0) {
                lasto = '(';
            }
            else if (b3 > 0) {
                lasto = '{';
            }
            else {
                lasto = '\0';
            }
        }
        else if (i == '}') {
            if (b3 == 0 || lasto != '{') {return false;}
            b3--;
            if (b1 > 0) {
                lasto = '(';
            } 
            else if (b2 > 0) {
                lasto = '[';
            } 
            else {
                lasto = '\0';
            }
        }

  }
  return (b1 == 0 && b2 == 0 && b3 == 0);
  }

  // Checks if a string is a palindrome.
  // An empty string is a palindrome.
  // A non empty string is a palindrome if it is equal to its reverse string.

  // Example 1: Input: "aba", output: true
  // Example 2: Input: "abba", output: true

  // You cannot use any std:: function.
  // Your memory usage should be O(1).
  bool CPPLib::IsPalindrome(const std::string& input){
        if (input.length()==0){ return true;}
        int i=0;
        int j=input.length()-1;

        while(i<j){  //midpoint, all comp done
            if (input[i]!=input[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true; //if while loop done it must be true
        
    }

  // Given a string, every letter appears even number of times except for one.
  // Find that letter!

  // Any solution that work is acceptable, but see if you can implement it while
  // keeping your memory usage as O(1).
  int CPPLib::OddChar(const std::string& input){
    int odd = 0;
    for (char i : input) {
        odd ^= i; //xor bitwise comp
    }
    return odd;
  }
