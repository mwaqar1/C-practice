# Food Ordering System

## Overview
This Food Ordering System, developed as part of an advanced programming workshop, is a sophisticated C++ application designed to manage daily food orders with dynamic memory management, command-line interaction, and file I/O operations. It dynamically handles variations in tax rates and daily discounts and is built using C++17 standards.

## Features
- **Command Line Arguments**: Receives arguments from the command line to initiate application functions based on user input.
- **Dynamic Memory Management**: Accepts and processes user-defined string lengths for food descriptions, ensuring flexibility and robustness.
- **Persistent Data Handling**: Utilizes static variables to maintain data consistency throughout the application lifecycle.
- **Advanced Debugging**: Integrated with debugging symbols for optimization using Valgrind and GCC tools.
- **Tax and Discount Calculation**: Automatically calculates prices based on current tax rates and daily discounts, updating in real-time.

## Technical Achievements and Skills Acquired
Key programming skills and techniques were developed and refined during this workshop:
- **Advanced Memory Management**: Mastered dynamic memory management to efficiently handle user-defined input lengths.
- **Command-Line Parsing**: Gained proficiency in parsing command-line arguments to enhance application usability and flexibility.
- **Lifetime Data Management**: Implemented static variables to ensure data remains valid and unchanged throughout the program's lifecycle.
- **Debugging and Testing**: Utilized GCC with advanced compiler options and Valgrind for debugging and memory leak detection.
- **C++ Standard Library**: Extensively used C++17 features, especially for string manipulation and file handling.
- **Linkage Concepts**: Developed an understanding of internal and external linkage to control visibility across different translation units.
- **Rule of Three**: Applied the Rule of Three for class management in C++ to ensure proper copy and move semantics.

## Installation

### Prerequisites
- GCC 10.2.0 or later
- Valgrind for memory leak detection
- A Linux-based operating system (recommended for full compatibility)

### Compiling the Program
Navigate to the project directory and run:
```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o FoodOrderApp ws file1.cpp file2.cpp ...
```
This command compiles the source files using C++17 standard and prepares an executable named FoodOrderApp.
## Usage

To run the application, use:

```bash

./FoodOrderApp day1.txt day2.txt
```
Replace day1.txt and day2.txt with your actual input files.
## Testing

For memory leak detection:

```bash

valgrind ./FoodOrderApp
```
Compare your program's output with provided sample outputs using a diff tool or similar file comparison tool for accuracy.
