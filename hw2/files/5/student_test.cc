#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(pushback, test1){ //got help from chatgpt on this, I dont understand why test needs have dyn mem
    int size=3;
  //  int *&array;

  //  *array[3] = {1,2,3};
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int element = 4;
    push_back(array, size, element);
    EXPECT_EQ(size, 4);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    EXPECT_EQ(array[3], 4);
    delete[] array;    

}


TEST(pushback, test2){ 
    int size=1;
    int *array = new int[size];
    array[0] = 1;
    int element = 4;
    push_back(array, size, element);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 4);
    delete[] array;    

}

TEST(pushback, test3){ 
    int size=0;
    int *array = new int[size];
    int element = 1;
    push_back(array, size, element);
    EXPECT_EQ(size, 1);
    EXPECT_EQ(array[0], 1);
    delete[] array;    

}


TEST(popback, test1){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    pop_back(array, size);   
    EXPECT_EQ(size, 2);  
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    delete[] array;
}

TEST(popback, test2){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    pop_back(array, size);   
    EXPECT_EQ(size, 2);  
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    delete[] array;
}

TEST(popback, test3){ 
    int size = 1;
    int *array = new int[size];
    array[0] = 1;
    pop_back(array, size); 
    EXPECT_EQ(size, 0);  
    delete[] array;
}

TEST(ins, test1){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int element = 4;
    int index = 2;
    insert(array, size, element, index);
    EXPECT_EQ(size, 4);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 4);
    EXPECT_EQ(array[3], 3);
    delete[] array;
}

TEST(ins, test2){ 
    int size = 0;
    int *array = new int[size];
    int element = 4;
    int index = 0;
    insert(array, size, element, index);
    EXPECT_EQ(size, 1);
    EXPECT_EQ(array[0], 4);
    delete[] array;
}

TEST(ins, test3){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int element = 4;
    int index = 5;
    insert(array, size, element, index);
    EXPECT_EQ(size, 3);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    delete[] array;
}

TEST(er, test1){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int index = 1;
    int output = erase(array, size, index);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(output, 0);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 3);
    delete[] array;
}

TEST(er, test2){ 
    int size = 1;
    int *array = new int[size];
    array[0] = 1;
    int index = 1;
    int output = erase(array, size, index);
    EXPECT_EQ(size, 1);
    EXPECT_EQ(output, -1);
    delete[] array;
}


TEST(er, test3){ 
    int size = 3;
    int *array = new int[size];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    int index = 9;
    int output = erase(array, size, index);
    EXPECT_EQ(size, 3);
    EXPECT_EQ(output, -1);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    EXPECT_EQ(array[2], 3);
    delete[] array;
}

TEST(fin, test1){ 
    int size = 3;
    int array[size] = {1, 2, 3};
    int element = 3;
    int output = find(array, size, element);

    EXPECT_EQ(output, 2);
}

TEST(fin, test2){ 
    int size = 3;
    int array[size] = {1, 2, 3};
    int element = 4;
    int output = find(array, size, element);
    EXPECT_EQ(output, -1);
}

TEST(fin, test3){ 
    int size = 0;
    int array[size] = {};
    int element = 4;
    int output = find(array, size, element);
    EXPECT_EQ(output, -1);
}