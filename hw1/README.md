[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/b8ByIHQA)

# HW1 EE538
## University of Southern California
## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc.
  We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:
  
| Question | Points |
| -------- | ------ |
| 1        | 18     |
| 2        | 18     |
| 3        | 18     |
| 4        | 18     |
| 5        | 18     |
| 6        | 18     |
| 7        | 18     |

- Total: 126 points. 100 points is considered full credit.


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
[TODO: Should be filled out with runtime complexity of each question with justification.]

1 a. O(n) becaus of while loop that goes through half the input vector's elements
  b. O(n) becasue of the 2 for loops that go through all the elements of the input vector

2 O(n) complexity because of the for loop going being executed the number of times the input /6 is
 
3 O(n) due to the for loop
4 O(n) due to the for loops iterating through the 3D vector
5 O(3^n) due to the 3 recursive calls to the function
6 O(1) because no loops, all constant time operations
7 subtr and loop causes O(n^2) because they both iterate through the strings the number of times thay the length of the strings are