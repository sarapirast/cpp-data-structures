#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
//data_ is privateeee
TEST(push_back, test1){ 
    MyVector vec1;
    int value = 4;
    vec1.push_back(value);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {4};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
 
}

TEST(push_back, test2){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    int value = 4;
    vec1.push_back(value);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {1,2,3,4};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 

}

TEST(pop_back, test1){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    int output= vec1.pop_back();
    int expected = 3;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(pop_back, test2){ 
    MyVector vec1;
    int output= vec1.pop_back();
    int expected = -1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kPopFromEmptyVector); 
}

TEST(pop_back, test3){ 
    MyVector vec1;
    vec1.push_back(1);
    int output= vec1.pop_back();
    int expected = 1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),0);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(push_front, test1){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_front(2);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {2,1};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),2);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(push_front, test2){ 
    MyVector vec1;
    vec1.push_back(2);
    vec1.push_front(2);
    vec1.push_front(3);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {3,2,2};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),3);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(pop_front, test1){ 
    MyVector vec1;
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_front(2);
    vec1.push_front(1);
    int output= vec1.pop_front();
    int expected = 1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),3);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(pop_front, test2){ 
    MyVector vec1;
    vec1.push_back(3);
    int output= vec1.pop_front();
    int expected = 3;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),0);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(pop_front, test3){ 
    MyVector vec1;
    int output= vec1.pop_front();
    int expected = -1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),0);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kPopFromEmptyVector); 
}

TEST(insert, test1){ 
    MyVector vec1;
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_front(2);
    vec1.push_front(1);
    vec1.insert(5,4);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {1,2,3,4,5};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),5);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(insert, test2){ 
    MyVector vec1;
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_front(2);
    vec1.push_front(1);
    vec1.insert(5,0);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {5,1,2,3,4};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),5);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(insert, test3){ 
    MyVector vec1;
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_front(2);
    vec1.push_front(1);
    vec1.insert(5,-1);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {5,1,2,3,4};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),5);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(insert, test4){ 
    MyVector vec1;
    vec1.insert(5,-1);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {5};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),1);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(insert, test5){ 
    MyVector vec1;
    vec1.insert(5,3);
    EXPECT_EQ(vec1.size(),0);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kIndexError); 
}

TEST(insert, test6){ 
    MyVector vec1;
    vec1.insert(5,-1);
    vec1.insert(4,-1);
    vec1.insert(2,-1);
    vec1.insert(1,-1);
    vec1.insert(3,2);
    std::vector<int> output = vec1.ConvertToStdVector();
    std::vector<int> expected = {1,2,3,4,5};
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),5);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}


TEST(at, test1){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    int output= vec1.at(2);
    int expected = 3;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),4);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}

TEST(at, test2){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    int output= vec1.at(6);
    int expected = -1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),4);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kIndexError); 
}

TEST(at, test3){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    int output= vec1.at(-2);
    int expected = -1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),4);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kIndexError); 
}


TEST(find, test1){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    int output= vec1.find(-2);
    int expected = -1;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),4);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNotFound); 
}


TEST(find, test2){ 
    MyVector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    int output= vec1.find(3);
    int expected = 2;
    EXPECT_EQ(output, expected);
    EXPECT_EQ(vec1.size(),4);
    EXPECT_EQ(vec1.get_error(), ErrorCode::kNoError); 
}
