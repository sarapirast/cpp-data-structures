#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(equal, test1){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue q2;   
    q2.Enqueue(4);
    q2.Enqueue(5);
    q2.Enqueue(6);  

    q1 = q2;  
    EXPECT_EQ(q1.GetData(),q2.GetData());

    q2 = q1;  
    EXPECT_EQ(q2.GetData(),q1.GetData());
}

TEST(equal, test2){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue q2;

    q1 = q2;  
    EXPECT_EQ(q1.GetData(),q2.GetData());

    q2 = q1;  
    EXPECT_EQ(q2.GetData(),q1.GetData());
}


TEST(equal, test3){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue q2;
    q2.Enqueue(3);

    q1 = q2;  
    EXPECT_EQ(q1.GetData(),q2.GetData());

    q2 = q1;  
    EXPECT_EQ(q2.GetData(),q1.GetData());
}

TEST(equal, test4){ 
    Queue q1;

    Queue q2;


    q1 = q2;  
    EXPECT_EQ(q1.GetData(),q2.GetData());

    q2 = q1;  
    EXPECT_EQ(q2.GetData(),q1.GetData());
}

TEST(sum, test1){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue q2;
    q2.Enqueue(4);
    q2.Enqueue(5);
    q2.Enqueue(6); 

    Queue q3 = q1 + q2;
    Queue q4 = q2 + q1;
     
    std::vector<int> expected3 = {4, 5, 6, 1, 2, 3};
    EXPECT_EQ(q3.GetData(),expected3);

    std::vector<int> expected4 = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(q4.GetData(),expected4);
}

TEST(sum, test2){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    Queue q2;


    Queue q3 = q1 + q2;
    Queue q4 = q2 + q1;
     
    std::vector<int> expected3 = {1, 2, 3};
    EXPECT_EQ(q3.GetData(),expected3);

    std::vector<int> expected4 = {1, 2, 3};
    EXPECT_EQ(q4.GetData(),expected4);
}

TEST(sum, test3){ 
    Queue q1;


    Queue q2;


    Queue q3 = q1 + q2;
    Queue q4 = q2 + q1;
     
    std::vector<int> expected3 = {};
    EXPECT_EQ(q3.GetData(),expected3);

    std::vector<int> expected4 = {};
    EXPECT_EQ(q4.GetData(),expected4);
}

TEST(Dequeue, test1){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Dequeue(); 
    std::vector<int> expected = {2, 3};
    EXPECT_EQ(q1.GetData(),expected);
    EXPECT_EQ(q1.IsEmpty(),false);
}

TEST(Dequeue, test2){ 
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Dequeue(); 
    q1.Dequeue();
    q1.Dequeue();
    std::vector<int> expected = {};
    EXPECT_EQ(q1.GetData(),expected);
    EXPECT_EQ(q1.IsEmpty(),true);
}

TEST(Dequeue, test3){ 
    Queue q1;
    q1.Dequeue(); 
    q1.Dequeue();
    std::vector<int> expected = {};
    EXPECT_EQ(q1.GetData(),expected);
    EXPECT_EQ(q1.IsEmpty(),true);
}


TEST(Dequeue, test4){ 
    Queue q1;
    q1.Enqueue(1); 
    q1.Dequeue();
    std::vector<int> expected = {};
    EXPECT_EQ(q1.GetData(),expected);
    EXPECT_EQ(q1.IsEmpty(),true);
}


TEST(front, test1){ 
    Queue q1;
    q1.Enqueue(1); 
    q1.Dequeue();
    int expected = -1;
    EXPECT_EQ(q1.Front(),expected);
    EXPECT_EQ(q1.IsEmpty(),true);
}

TEST(front, test2){ 
    Queue q1;
    q1.Enqueue(1); 
    int expected = 1;
    EXPECT_EQ(q1.Front(),expected);
    EXPECT_EQ(q1.IsEmpty(),false);
}

TEST(front, test3){ 
    Queue q1;
    q1.Enqueue(1); 
    q1.Enqueue(2); 
    q1.Enqueue(3); 
    q1.Enqueue(4); 
    int expected = 1;
    EXPECT_EQ(q1.Front(),expected);
    EXPECT_EQ(q1.IsEmpty(),false);
}