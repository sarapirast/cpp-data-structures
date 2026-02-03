#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


// Returns the index of the fist space character in a string.
// Returns -1 if there are no spaces.
// Don't use any of STL helper functions such as find.
int IndexOfFirstSpace(std::string &input){
    for (int i= 0; i < input.length(); i++){
        if (input[i] == ' ') //check for space char
        return i;
    }
    return -1;
}



// Given the full_name, it returns the first_name and last_name.
// Note: you should use IndexOfFirstSpace function and cannot use any other
// std:: functions.
// If there is no space, set the last_name to an empty string.
// If the string is empty, both first and last name should be empty strings.
// You can use substr function from the string class.
void SeparateFirstAndLastNames(std::string &full_name, std::string &first_name, std::string &last_name){
int index = IndexOfFirstSpace(full_name);

if (full_name== ""){  //check if it is an empty string
    last_name = "";
    first_name = "";
}

else if (index == -1){ //if no space
    last_name = "";
    first_name = full_name;
}
else { //what the function does
    last_name = full_name.substr(index+1); //index + 1 to end
    first_name = full_name.substr(0,index); //index included here so index +1 for last name
}

}



// implement a helper function splitString that takes in a string and returns a
// vector of strings split by spaces.
// - Do not use any other class from STL such as `istringstream` that are not
// discussed in our lectures.
// - You can use std::string's find function.
std::vector<std::string> SplitString(const std::string &str){
 int i; //need them outside for loop
 int j = 0;
 std::vector<std::string> output; //vector of strings

// find returns string::npos when not found so loop for duration which space is found
 for (i = str.find(' ',j); i!=std::string::npos; i = str.find(' ',j)){
    if (i>j){
    output.push_back(str.substr(j, i - j)); //from begin until space found
    }
    j = i + 1;
 }
 if (j != str.length())
 output.push_back(str.substr(j)); //last part thats not included in the loop isnce no space at the end
return output;
}



// Suppose you have a string with multiple words separated by spaces. Implement
// a function CalculateFrequency that takes in this string and returns a map
// where the key is the word and the value is its frequency in the string.
// In your implementation you can use:
// - SplitString function in your implementation.
// - std::string's find function.
// - std::vector.

// Example
// input: "apple banana orange apple apple banana"
// Output:
// apple: 3
// banana: 2
// orange: 1
std::map<std::string, int> CalculateFrequency(const std::string &input){
    std::map<std::string, int> freq;
//map is like dict
    std::vector<std::string> vec = SplitString(input); //vector of the words in the string
    for (auto i: vec){
        freq[i]++; //for items in vector add them to the map, map increases key value if same item added
    }

return freq;
}
