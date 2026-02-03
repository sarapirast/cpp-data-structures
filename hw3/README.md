[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/rReGWuey)
# HW3 EE538

## University of Southern California

## Instructor: Arash Saifhashemi

Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

## Important:

- Use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:

- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Rubrics:

| Question | Points |
| -------- | ------ |
| 1        | 16     |
| 2        | 20     |
| 3        | 20     |
| 4        | 20     |
| 5        | 24     |

- 100 points is considered full credit.

See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.

# Question
- Please refer to [files](/files).
- For each question, implement and test it in the [files](/files).
- Write the runtime complexity of each question in this README file.

# Answers
[TODO: Should be filled out with runtime complexity of each question with justification.]

Runtime:
taking max of the different funcions in each
Q1: NA
Q2: O(n) (loop)
Q3: O(n) (loop)
Q4: O(1) (no loop)
Q5: O(n) (loop)

FILE 1
Q1 ouput is:

Q1  //explicitly printed
Non-parameterizedconstructor //what the constructor prints (no parameters given to MyClass here)
o1.v_.size(): 0  //v_ is empty so size is 0
Destructor //what the destructor prints


---------------------------------------------------------------

Q2 ouput is:

Q2 //explicitly printed
Non-parameterizedconstructor //what the constructor prints (no parameters given to MyClass here)
Parameterized constructor  //o2 has parameters a, b calls the parametrized const
Copy constructor //becase copying o1 to o3 and calling the copy constructor
Destructor
Destructor
Destructor //3 constructors so 3 Desctructors are used


---------------------------------------------------------------

Q3 ouput is:

Q3 //explicitly printed
Non-parameterized constructor //what the constructor prints (no parameters given to MyClass here) 
Copy constructor //DoSomething1(o) invokes the copy constructor as well as prints the next line (because o is a value here)
Something 1.
Destructor
Destructor //2 constructors so 2 Desctructors are used


---------------------------------------------------------------

Q4 ouput is:

Q4 //same as previous (hard coded)
Non-parameterized constructor //what the constructor prints (no parameters given to MyClass here) 
Something 2. //reference o, no copy const
Destructor //1 const 1 dest


---------------------------------------------------------------

Q5 ouput is:

Q5
Non-parameterized constructor
Something 3. //something3 same as something 2, no copy const
Destructor
//everything same as Q4


---------------------------------------------------------------

Q6 ouput is:

Q6
Non-parameterized constructor //same as prev
Copy constructor //something 4 uses copy const as well as printing line below
Something 4. 
Destructor
Destructor //2 const so 2 dest


---------------------------------------------------------------

Q7 ouput is:

Q7
Parameterized constructor //MyClass(1,2) calls the parametrized const
Copy constructor //p1 = uses copy const
Destructor //destruct p1 =
p1.first.v_.size(): 0 //size of p1.first.v_.size()
p1.second: 0 //is of p1.second
Copy constructor //copying p1 to p2
Destructor //deconstruct copy cons for p2
p2.first.v_.size(): 0 //same as p1.first...
p2.second: 0 //same as p1.second
Destructor //2 dest, destricting p2.first and p1.first
Destructor


---------------------------------------------------------------

Q8 ouput is:

Q8
Parameterized constructor // MyClass with parameters (1,2) so prints para...
Something 2. //for loop calls something 2 3 times
Something 2.
Something 2.
Destructor //destruct the param constr


---------------------------------------------------------------

Q9 ouput is:

Q9
Parameterized constructor //calls the param constructor, no destructor leads to memory leak, because o = MyClass(1,2) the dest was not called


---------------------------------------------------------------

Q10 ouput is:

Q10
Parameterized constructor //MyClass(1,2)
Destructor //delete o calls the dest


---------------------------------------------------------------

Q11 ouput is:

Q11
Non-parameterized constructor //MyClass()
Parameterized constructor //MyClass(1, 2)
Parameterized constructor //MyClass(3, 4)
Copy constructor  //for loop calls copy 3 times
Copy constructor
Copy constructor
Destructor //destructing all the constr
Destructor
Destructor
Destructor
Destructor
Destructor


---------------------------------------------------------------

Q12 ouput is:

Q12
Non-parameterized constructor //same as last one
Parameterized constructor
Parameterized constructor
Copy constructor
Copy constructor
Copy constructor
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor


---------------------------------------------------------------

Q13 ouput is:

Q13
Parameterized constructor
Destructor //delete o calls decons


---------------------------------------------------------------

Q14 ouput is:

Q14
Parameterized constructor //my class with param
Operation took: ... milliseconds  // the amount of time it would take to run MyClass o(100000000) (not sure how to get it)
Copy constructor //for loop has o2=o needs copy const
Something 1.
o2.v_.size(): 100000000
Copy constructor
Something 1.
o2.v_.size(): 100000000 //size of input
Destructor //dest the 2 copy const
Destructor
Operation took: ... milliseconds //for loop time
Destructor struct the param const


---------------------------------------------------------------

Q15 ouput is:
//same as Q14
Q15
Parameterized constructor //myclass call uses this const
Operation took: ... milliseconds  //time for MyClass o(100000000) to execute
Copy constructor //o2 = o copies
Something 2.
o2.v_.size(): 100000000 //param szie
Copy constructor
Something 2.
o2.v_.size(): 100000000
Destructor
Destructor
Operation took: ... milliseconds //loop duration
Destructor


---------------------------------------------------------------

Q16 ouput is:

Q16
Parameterized constructor  //for each comp of myvector
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Parameterized constructor
Operation took: ... milliseconds //time to assign the above
Copy constructor //for loop for param of each comp of myvector
e.v_.size(): 10000000 //param
Destructor //for the copy const (deleted after for loop for this param ends)
Copy constructor
e.v_.size(): 20000000
Destructor
Copy constructor
e.v_.size(): 30000000
Destructor
Copy constructor
e.v_.size(): 40000000
Destructor
Copy constructor
e.v_.size(): 50000000
Destructor
Copy constructor
e.v_.size(): 60000000
Destructor
Copy constructor
e.v_.size(): 70000000
Destructor
Operation took: ... milliseconds //time it took for for loop to finish
e.v_.size(): 10000000 //since deref no copy const needed for this for loop more time
e.v_.size(): 20000000
e.v_.size(): 30000000
e.v_.size(): 40000000
e.v_.size(): 50000000
e.v_.size(): 60000000
e.v_.size(): 70000000
Operation took: ... milliseconds //time for this loop this would take less time
Destructor //for the param const 
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor