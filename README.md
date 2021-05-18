# Rustduino Assignment

This repository contains 4 question related to programming in C. You're supposed to do only 2 questions out of 4. _(Feel free to do additional questions, marks will be adjusted accordingly.)_ Students whose ESC101 has been completed and those whose ESC101 has not been completed will be judged separately and marks will be normalized.

## Question 1 (10 points)

Write a C/C++ program that performs the following actions:

Prompts the user to input their name.
Prints a greeting to the user, calling them by their name.
Prompts the user to input the year they were born.
Calculates and prints the user's age.

Example:

```
What is your name?
> Alan Turing
Hello, Alan Turing!
What year were you born?
> 1912
Congratulations, you are 106 old!
```

## Question 2 (20 points)

Write a C program that performs the following tasks:

1. It prompts the user to enter a string to search for, for example “Microprocessor”.
2. It thenproceeds by reading the module catalogue stored in the file courses.txt, where each line contains a description of one module. Here is a short fragment from the file:

```
...
EEE1008 C Programming
EEE1009 Communication Skills and Innovation
EEE1010 Electronics I for Electronics and Computer Eng
EEE2007 Computer Systems and Microprocessors
...

```

The file is given as courses.txt.

3. For every line in the file, the program checks whether it contains the search string S. If yes, it prints out thisline. For example, the line corresponding to the EEE2007 course (see above) contains the string “Microprocessor” and should be printed. Note: string matching should be case-sensitive, i.e. “Microprocessors” is different from string “microprocessor”.

4. When all lines have been processed, the program prints the number of found matches. See examples below for a clarification. Note:you do not have to follow exactly the same input and output format as shown in the examples.You are also encouraged to experiment by adding otheruseful featuresfor manipulating the information provided in the module catalogue.Examples:

```
Enter a search string: Microprocessor
EEE2007 Computer Systems and Microprocessors
EEE2206 Computer Systems and Microprocessors
EEE3010 Microprocessor Control
EEE8022 Microprocessor Systems
Number of matches: 4
```

```
Enter a search string: circuits
Number of matches: 0
```

## Question 3 (20 points)

In this assignment you will implement a simple calculator that allows users to enter and evaluate arithmetic expressions like 1 + 2 \* 3, taking care of possible input and calculation errors.
Write a C/C++ program that performs the following tasks:

1. It prompts the user to enter an expression withthree numbers and two operators.Your program should support integer numbers in the range from 0to 1000, and arithmetic operators +, -, \* and /. The program should check the input correctness, and if an error is detected, report an error message and terminate the program.
2. The program proceeds to evaluate the expression, respecting the operator precedence. In case of a calculation error, such as division by zero, the program should terminate.
3. Finally, the program prints out the result and terminates successfully with the return code 0. See examples below for a clarification.

Note: you do not have to follow exactly the same input and output format as shown in the examples.

Below are three examples of successful program execution:

```
Enter an expression: 0 + 1 + 2
Result: 3
```

```
Enter an expression: 1 + 2 * 3
Result: 7
```

```
Enter an expression: 2 - 10 - 1000
Result: -1008
```

This is an example of an incorrect expression entered by the user:

```
Enter an expression: 1 + 2 + 2000
Incorrect input: numbers cannot exceed 1000. Program terminated, please try again.
```

## Question 4 (5 points per Bug. Limit : 30)

It is a worthwhile exercise to work through an example to understand the depth of problems that can occur when dealing with memory in C, and to appreciate how Rust can prevent such bugs. In the file vector.c, I have provided an implementation of a vector library (i.e. resizable array). It contains several bugs relating to the properties of memory safety, containment and access. Your task is to find out as many bugs you can. Also, you are expected to give a small explanation of how you arrived at theses bugs. You can possibly give upto 10 bugs, you will be only awarded marks for correct bugs.
