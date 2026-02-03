[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/whp8wjMI)
# EE538 Midterm Exam

## 
    University of Southern California

## Instructor: Arash Saifhashemi

## Important:

- A lot of time and effort has been spent to design this exam for you. Please use this as a great learning opportunity and take this exam seriously.
- Please make sure you abide by the academic integrity rules and only submit your original work. All the rules described in Q1 of the Gradescope exam applies here as well.
- Make sure you use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Run your tests for each question using this command:

```
bazel test --cxxopt="-std=c++17" --config='asan' files/{question_number}/grader_test
```

Before submission, you can run all the tests for all questions using this command:

```
bazel test --cxxopt="-std=c++17" --config='asan' $(bazel query //files/... | grep grader)
```

Also note that:

- Important: Don't modify the header files. Your implementation should go in .cc files.
- Please find each question in a separate folder under [files](/files).
- For coding questions, edit the files and check them in.
- For non-coding questions write the answers in the README file (This file).
- No need to write complete student tests. Your code must pass grader tests.
- For submission, please push your answers to Github before the deadline.

| Question | Points |
| -------- | ------ |
| 1        | 25     |
| 2        | 25     |
| 3        | 10     |
| 4        | 20     |

- Total: 80 points.
- Getting 100 points from the sum of the points in this repo plus the points in Gradescope exam is considered full credit.
  - For example, if you get 80 from this repo and 25 from Gradescope, your total would be 105, which means you received full credit!

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


#3 
1 
Q1: to allocate enough space for the output array since arrays need to have their size defined initially
Q2: the sum of size_1 + size_2

2
Q1: We didn't provide the sizes because vector are resizable and their size isn't needed by the compiler initially.
Q2: Yes this is allowed in c++, this works because they take in different types of inputs, if the input types were the same then no it would not be allowed