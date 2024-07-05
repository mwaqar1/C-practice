# Multi-Threading Workshop: Average Calculation

## Project Overview
This project showcases the implementation of a C++ application designed to efficiently process large data sets using multi-threading. The main functionality involves reading numbers from binary files, computing their averages and variances, and writing the results back to binary files. The application leverages advanced C++ features and threading to improve performance and efficiency.

## Key Features
- **Binary File Operations**: Implements binary read/write operations to manage data efficiently, reducing file size and improving I/O speed.
- **Multi-threading**: Utilizes multiple threads to simultaneously read data and calculate statistics, significantly reducing processing time.
- **Function Binding**: Uses `std::bind` and lambda functions to prepare functions with fixed parameters for thread execution, enhancing modularity and reusability.

## Technical Achievements
- **Performance Optimization**: Achieved notable improvements in processing speeds by effectively distributing tasks across multiple threads.
- **Resource Management**: Enhanced responsiveness and resource utilization by enabling concurrent processing tasks on multi-core processors.
- **Robustness and Accuracy**: Ensured the application's reliability and accuracy through comprehensive testing, including memory leak checks using Valgrind.

## Skills Gained
- **Advanced C++ Programming**: Gained proficiency in using modern C++17 features including lambda expressions, threading, and file handling.
- **Concurrency Management**: Developed a strong understanding of multi-threading concepts, thread synchronization, and thread safety.
- **Performance Analysis**: Experienced in performance tuning and debugging complex applications using G++ and Valgrind.

## How to Run the Program
1. Compile the program using:

```
/usr/local/gcc/10.2.0/bin/g++ -Wall -pthread -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

2. To check for memory leaks, run:

```
valgrind ./ws
```

3. Execute the program:

```
./ws data_int.dat data_int_target.dat
```

## Reflection
This project provided insights into the advantages of binary file usage, the importance of binding functions to arguments, and the benefits of multi-threading in software development. 


