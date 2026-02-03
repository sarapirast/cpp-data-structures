#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

//evenVec_ and oddVec_ private

TEST(pop, test1){ 
    DoubleStack s1;
    s1.push(1); 
    s1.push(2);
    s1.pop();
    //EXPECT_EQ(s1.size(),0);
    //EXPECT_EQ(s1.empty(),true);
    EXPECT_EQ(s1.size(),1);
    EXPECT_EQ(s1.empty(),false);
    
}

TEST(pop, test2){ 
    DoubleStack s1;
    s1.push(1); 
    s1.push(2);
    s1.push(3); 
    s1.push(4);
    s1.pop();
    EXPECT_EQ(s1.size(),3);
    EXPECT_EQ(s1.empty(),false);
}

TEST(pop, test3){ 
    DoubleStack s1;
    s1.pop();
    EXPECT_EQ(s1.size(),0);
    EXPECT_EQ(s1.empty(),true);
}

TEST(pop, test4){ 
    DoubleStack s1;
    s1.push(1); 
    s1.pop();
    EXPECT_EQ(s1.size(),0);
    EXPECT_EQ(s1.empty(),true);
}

TEST(pop, test5){ 
    DoubleStack s1;
    s1.push(12); 
    s1.pop();
    EXPECT_EQ(s1.size(),0);
    EXPECT_EQ(s1.empty(),true);
}



TEST(top, test1){ 
    DoubleStack s1;
    s1.push(1); 
    s1.push(2);
    EXPECT_EQ(s1.top(),2);
    EXPECT_EQ(s1.empty(),false);
    EXPECT_EQ(s1.size(),2);

}

TEST(top, test2){ 
    DoubleStack s1;
    s1.push(1); 
    s1.push(2);
    s1.push(8);
    s1.push(4);
    s1.push(3);
    EXPECT_EQ(s1.top(),4);
    EXPECT_EQ(s1.empty(),false);
    EXPECT_EQ(s1.size(),5);
}

TEST(top, test3){ 
    DoubleStack s1;
    s1.push(1); 
    s1.push(2);
    s1.push(8);
    s1.push(4);
    s1.push(7);
    EXPECT_EQ(s1.top(),7);
    EXPECT_EQ(s1.empty(),false);
    EXPECT_EQ(s1.size(),5);

}

TEST(top, test4){ 
    DoubleStack s1;
    s1.push(3);
    EXPECT_EQ(s1.top(),3);
    EXPECT_EQ(s1.empty(),false);
    EXPECT_EQ(s1.size(),1);

}

TEST(top, test5){ 
    DoubleStack s1;
    s1.push(4);
    EXPECT_EQ(s1.top(),4);
    EXPECT_EQ(s1.empty(),false);
    EXPECT_EQ(s1.size(),1);

}

TEST(top, test6){ 
    DoubleStack s1;
    EXPECT_EQ(s1.top(),-1);
    EXPECT_EQ(s1.empty(),true);
    EXPECT_EQ(s1.size(),0);

}