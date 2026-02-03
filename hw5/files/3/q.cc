#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
int Fibonacci(int n){
//O(n) so no recurssion?
// if (n <= 1) return n;
//return Fibonacci(n - 1) + Fibonacci(n - 2);
// Fn = Fn-1 + Fn-2;
    if (n<=1) return 1;
    int fn1=1;
    int fn2=1;
    for (int i=2; i<=n; i++){
        int  temp= fn1+fn2;
        fn1=fn2;
        fn2=temp;
    }
return fn2;

}
