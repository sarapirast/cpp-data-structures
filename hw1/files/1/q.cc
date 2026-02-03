#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


std::vector<int> Reverse(std::vector<int> input){
int i= 0;  
int j= input.size()-1;

std::vector<int>temp(j+1);

while (j>=i){

temp[i] = input[j];
temp[j] = input[i];   //swap the values
//iterate
i++;
j--;

}

return temp;

/* 0 1 2 3 4 5 6
   - - - - - - -
   a           b
   ^           ^
   |           |
              

  6 5 4 3 2 1 0
  - - - - - - -
  ^           ^
  |           |
  a           b
  
*/

}
//O(n) because of while loop

std::vector<int> PlusOne(std::vector<int> input){
  std::vector<int>error = {-1};
  if (input.size()==0) return {};
  int j= input.size();
for (int i=0;i<j;i++){
  if (input[i]>9 || input[i]<0){
    return error;
}
}


  for (int i=j-1;i>=0;i--){
    if (input[i] < 9) {
      input[i]++;
      return input;
    }
    input[i]=0;  //if input[i]==9
  }
  input.insert(input.begin(), 1);    
  return input;
} 
//plusone O(n) becasue of the for loops

