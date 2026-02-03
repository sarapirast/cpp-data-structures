#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc



bool IsMinHeap(const std::vector<int> &heap){
//root node must be less than or equal among the keys present at all of its children.
//The same property must be recursively true for all sub-trees in that Binary Tree
int len = heap.size();

for (int i=0; i<= len;i++){
    int lc= (2*i)+1; //left child based on array index
    int rc= (2*i)+2; //right child after left one

    if (lc < len) {
        if (heap[i]>heap[i]) return false; //left node
    }
    if (rc < len) {
        if (heap[i]>heap[lc]) return false; //right node
    }
    return true;
}
}

void ConvertToMinHeap(std::vector<int> &in){
    int len = in.size();
    for (int i= (len/2)-1; i>=0;--i){
        int cur= i;
        while (true){
            int lc= 2*cur+1;
            int rc= 2*cur+2;
            int small= cur;

            if (lc < len && in[lc] < in[small]){
                small= lc;
            }
            if (rc < len && in[rc] < in[small]){
                small= rc; 
            }
            if (small== cur) {
                break;
            }

            int temp= in[cur];
            in[cur]= in[small];
            in[small]= temp;
            cur= small;
        }         
    }
}