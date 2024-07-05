# STL Algorithms - Baked Goods Management Application 

## Overview
This C++ application effectively manages a collection of baked goods utilizing the Standard Template Library (STL). Designed as part of an academic workshop, it showcases the application of STL algorithms, lambda expressions, and robust data management techniques.

## Project Features
- **Data Import**: Automated copying of data from files into STL containers.
- **Algorithmic Efficiency**: Use of various STL algorithms like `std::sort`, `std::for_each`, `std::accumulate`, and `std::copy_if` for data processing.
- **Lambda Functionalities**: Implemented lambda expressions to customize operations dynamically on data sets.
- **Sorting and Querying**: Development of a no-loop sorting function to organize bakery items based on multiple attributes.
- **Performance Optimization**: Application tested under strict conditions using Valgrind and GCC to ensure optimal performance and reliability.

## Skills Gained
- **Modern C++ Proficiency**: Gained in-depth knowledge of C++17 features and STL usage.
- **Algorithmic Thinking**: Enhanced ability to apply STL algorithms to efficiently solve data manipulation problems.
- **Debugging Skills**: Acquired advanced debugging skills through the use of GCC flags and Valgrind for memory leak checks.
- **Code Maintainability**: Emphasis on writing clear, maintainable code while adhering to academic integrity and documentation standards.
- **Problem Solving**: Improved problem-solving capabilities by addressing complex requirements with algorithmic strategies.

## Compilation and Testing
Compile the application with the following GCC command:

```
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

Check for memory leaks using Valgrind:

```
valgrind ./ws
```

To run the application:

```
./ws bakery-goods.txt
```

## Reflection

Reflecting on the project, it is evident that using STL algorithms not only simplifies the implementation but also enhances the performance and maintainability of C++ applications. This workshop significantly bolstered my C++ skills, particularly in understanding and applying complex STL algorithms in real-world scenarios.


