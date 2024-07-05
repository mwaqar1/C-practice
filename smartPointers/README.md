# Smart Pointers Workshop

## Project Overview
This repository contains the implementation for the Workshop 8: Smart Pointers, a C++ based project focused on employing advanced programming techniques with smart pointers to manage memory effectively. The project is divided into multiple parts, each addressing different aspects of smart pointer usage within a complex software system, culminating in a comprehensive application that demonstrates the Singleton pattern, template programming, and memory management.

## Technical Achievements

- **Singleton Pattern Implementation**: Successfully utilized the Singleton design pattern through static members to ensure that only a single instance of the `Database` class exists within the application, optimizing resource allocation and program stability.

- **Memory Management**: Integrated `std::shared_ptr` for managing dynamic memory more safely and efficiently, preventing memory leaks and ensuring proper resource cleanup.

- **Quadratic Complexity Management**: Developed components with quadratic complexity, showcasing the ability to optimize and manage complex algorithms within the software.

- **Template Programming**: Adapted the `Database` class to be templated, allowing it to handle various data types dynamically which enhances the modularity and flexibility of the codebase.

- **Custom Encryption and Decryption**: Implemented template specialization for encryption and decryption functions tailored to different data types, enhancing data security within the application.

- **Valgrind Integration**: Employed Valgrind for memory leak detection and debugging during the development process, ensuring the reliability and robustness of the memory management system.

## Skills Gained

- **Advanced C++ Programming**: Enhanced skills in using modern C++17 features including smart pointers, templates, and advanced data structures.

- **Memory Optimization**: Gained substantial experience in dynamic memory management and optimization techniques, crucial for developing high-performance applications.

- **Security Practices**: Developed understanding and practical skills in implementing basic encryption and decryption mechanisms within software applications.

- **Software Design Patterns**: Deepened knowledge of design patterns, specifically the Singleton pattern, and their applications in software design to solve common development issues.

- **Debugging and Profiling**: Advanced proficiency in using debugging and profiling tools like Valgrind to ensure the application is free of memory leaks and other performance issues.

## Compilation and Testing

Compile the project using the following command:

```
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

To check for memory leaks:

```
valgrind ./ws
```

## Reflections

This project provided a comprehensive understanding of memory management in C++ using smart pointers, the importance of software design patterns in creating efficient software solutions, and the use of advanced C++ features in real-world applications. The learning outcomes have been instrumental in refining my approach to software development, particularly in aspects of efficiency and reliability.

