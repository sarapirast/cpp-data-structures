#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int ClimbStairs(int n){
    if (n == 0)
        return 0; //can't climb
    if (n>=45)
        return 0;
    if (n<0)
        return -1; //can't climb
    if (n==1)
        return 1; //1 way to climb
    if (n==2)
        return 2; //2 ways to climb
    if (n==3)
        return 4; //4 ways to climb
    return ClimbStairs(n-3)+ClimbStairs(n-2)+ClimbStairs(n-1);
    //-3 not -4?? number of stairs not ways

    //number of ways to climb max 3 stairs = 4
    // ex. if n= 44 -4 + -2 + -1 ? 
}
