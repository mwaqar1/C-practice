# Workshop 4: Containers

## Project Overview
This project involves developing a simulation of a children's toy ordering system, utilizing advanced object-oriented programming techniques in C++. The application models interactions between objects using composition and aggregation relationships to mimic a realistic order system for toys.

## Technologies Used
- **Programming Language:** C++
- **Compiler:** GCC 10.2.0
- **Debugger Tools:** GDB, Valgrind
- **Other Tools:** diff (for output comparison)

## Features
The project is structured into two main parts:
1. **Part 1:** Basic implementation of the `Toy` class.
2. **Part 2:** Extension with the `Child` and `ConfirmOrder` classes, incorporating dynamic memory management and complex class relationships.

### Key Components
- **Toy Class:** Manages toy details including ID, name, price, and quantity.
- **Child Class:** Manages a collection of toys, demonstrating the concept of composition.
- **ConfirmOrder Class:** Handles an aggregation of toys, facilitating order confirmations without owning the toy objects.

## Technical Achievements
- **Class Design:** Demonstrated proficiency in designing and coding composition and aggregation class relationships.
- **String Manipulation:** Employed C++ string class functions to parse and process string data into class attributes.
- **Dynamic Memory Management:** Implemented a system managing dynamic allocations using double pointers, enhancing application stability and memory handling.
- **Compilation and Debugging:** Compiled the application using specific GCC flags and debugged using GDB and Valgrind to ensure reliability and performance.

## Skills Gained
- **Advanced Object-Oriented Programming:** Gained deeper insights into object interactions within software through real-world simulations.
- **Efficient Data Handling:** Enhanced abilities in managing data parsing and dynamic memory, crucial for developing high-performance software.
- **Debugging and Testing:** Developed a rigorous approach to software testing and debugging, ensuring thorough verification and validation of application behavior.
- **Problem-Solving:** Strengthened problem-solving skills, particularly in addressing the challenges associated with memory management and data parsing in a structured environment.

## How to Run
Ensure you have GCC installed and your environment is set up to use the GCC 10.2.0 compiler. Compile the project using:
```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

Run the compiled application with:

```
./ws data.txt
```
Check for memory leaks using:

```
valgrind ./ws
```

