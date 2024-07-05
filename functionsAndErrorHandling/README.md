#  Functions and Error Handling Workshop

## Project Description
In this intensive C++ workshop titled "Functions and Error Handling", I developed a highly functional and error-resilient application capable of managing collections of objects through a sophisticated class template. The template enabled the registration and notification of callbacks, illustrating a practical implementation of the observer design pattern with robust exception handling.

## Technical Achievements

- **Class Template Design**: Implemented a generic class template capable of managing collections of type `T`, which allows dynamic memory management and object lifecycle control.
- **Function Object and Lambda Expression**: Created a function object to autocorrect spelling mistakes and a lambda expression to adjust incorrect price data, demonstrating advanced use of C++ callable objects.
- **Exception Handling Mechanisms**: Developed comprehensive error handling to manage exceptions from file operations and invalid data access, ensuring the application's reliability and robustness.
- **File-based Input/Output**: Engineered file input and output handling that loads and corrects data from text files, critical for real-world data processing applications.

## Skills Developed

- **Advanced C++ Programming**: Enhanced understanding and application of modern C++ features such as templates, lambda expressions, and function objects.
- **Exception Handling**: Gained significant expertise in designing error handling mechanisms to manage runtime exceptions effectively.
- **Observer Pattern**: Acquired practical experience in implementing design patterns, specifically the observer pattern, to manage dependencies gracefully.
- **Debugging and Memory Management**: Improved debugging skills and memory management practices, ensuring optimal application performance and stability.

## Compilation and Execution

To compile the project, use the following command:

```
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```
To execute the program and check for memory leaks, run:

```
valgrind ./ws
```
 Learning

This workshop significantly improved my practical C++ skills, particularly in utilizing advanced features and handling complex scenarios with error-prone data. It also underscored the importance of clean, maintainable code and deepened my understanding of functional and object-oriented programming paradigms in C++.
