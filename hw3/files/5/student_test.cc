#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Valid, test1) {
    CPPLib b;
    EXPECT_EQ(b.CheckValidExpression("(a+b)"), true);
    EXPECT_EQ(b.CheckValidExpression("(a+b)[c*d]{5g+h}"), true);
    EXPECT_EQ(b.CheckValidExpression("{2k+[5j]}"), true);
    EXPECT_EQ(b.CheckValidExpression(""), true);
    EXPECT_EQ(b.CheckValidExpression("(a+b]"), false);
    EXPECT_EQ(b.CheckValidExpression("(7h+[5c)+7]"), false);
    EXPECT_EQ(b.CheckValidExpression("{[}]"), false);
}

TEST(Pal, test2) {
    CPPLib v;

    EXPECT_EQ(v.IsPalindrome(""),true);      
    EXPECT_EQ(v.IsPalindrome("a"),true);
    EXPECT_EQ(v.IsPalindrome("abcde"),false);
    EXPECT_EQ(v.IsPalindrome("abba"),true);
    EXPECT_EQ(v.IsPalindrome("aba"),true);
}

TEST(Odd, test3) {
    CPPLib odd;

    EXPECT_EQ(odd.OddChar("abbac"), 'c');
    EXPECT_EQ(odd.OddChar("abcabcxyx"), 'y');
    EXPECT_EQ(odd.OddChar("aabbcc"), 0);
    EXPECT_EQ(odd.OddChar(""), 0); 
}
