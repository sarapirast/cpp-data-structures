#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(StudentMaxHeap, HeapOperations) {
    std::vector<Student> input = {
        {"A", 90},
        {"B", 85},
        {"C", 95},
        {"D", 70},
        {"E", 88}
    };
    StudentMaxHeap heap(input);
    EXPECT_EQ(heap.top().name, "C");
    EXPECT_EQ(heap.top().grade, 95);

    heap.pop();
    EXPECT_EQ(heap.top().name, "A");
    EXPECT_EQ(heap.top().grade, 90);

    HeapSort(input);
    std::vector<int> expected_grades = {70, 85, 88, 90, 95};
    for (size_t i = 0; i < input.size(); ++i) {
        EXPECT_EQ(input[i].grade, expected_grades[i]);
    }
}
