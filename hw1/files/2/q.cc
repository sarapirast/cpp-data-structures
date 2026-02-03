#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
bool IsPrime(int number){
    //prime if only divisible by itself
    //ie. not divisable by 2,3,etc. formula 6k+-1
    //cant have negative
    if (number <=1)
        return false;
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 ==0)
        return false;
for (int i=0; i<=number/6;i++){
    if (number % (6*i-1)== 0 || number % (6*i+1)== 0)
    return true;
}


//O(n) complexity because of the for loop


// 6i-1=number
// i from 0 to number/2?


return false;

}
