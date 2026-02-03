[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/97_OgHWb)
# EE538 - Homework 5

# University of Southern California

## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

- Please find each question in a separate folder under [files](/files).

| Question | Points   |
| -------- | -------- |
| 1        | 10       |
| 2        | 30       |
| 3        | 10       |
| 4        | 30       |
| 5        | 30       |
| 6        | Optional |
| 7        | Optional |

- 100 points is considered full credit.

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.
# EE538_Fall24_HW5

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
[TODO: Should be filled out with runtime complexity of each question with justification.]

Q1. O(row*col) because of the while loop, it iterates through each element of the maze (BFS)

Q2. For each function its different but the max is O(n^2) because my Dijkstra func has the for loop iterating through each edge and then within that it is iterating through all weigths to fnd min

Q3. O(n) because the for loop iterates through 2-n

Q4. O(n^2)recurssion, O(n)recurssion, O(n) for loop through all input vec

Q5. O(2^2)recursion, O(n) recursion, O(n) for loop 