#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(CanBecomeTest, less) { 
    int actual = CanBecome("12345", "1235");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, identical) { 
    int actual = CanBecome("12345", "12345");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, empty1) { 
    int actual = CanBecome("12345", "");
    EXPECT_EQ(0, actual); 
}

TEST(CanBecomeTest, empty2) { 
    int actual = CanBecome("", "");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, space) { 
    int actual = CanBecome(" ", " ");
    EXPECT_EQ(1, actual); 
}

TEST(CanBecomeTest, emptyspace) { 
    int actual = CanBecome(" ", "");
    EXPECT_EQ(0, actual); 
}
