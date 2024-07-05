# C++ Templates Workshop

This repository contains the deliverables for the C++ Templates Workshop conducted at Seneca College. The project focuses on the design and implementation of class templates, demonstrating the power and flexibility of C++ templates in software development.

## Project Overview

The primary objective of this workshop was to develop a deep understanding of C++ templates, allowing for the creation of generic and reusable software components. The project involved several key tasks such as designing class templates, templating class variables, and specializing templated class variables for specific types.

## Technical Achievements

- **Class Template Design and Coding**: Developed multiple class templates to handle various data types dynamically, showcasing the ability to write scalable and type-safe code.
- **Template Specialization**: Implemented specialized functions within templated classes that efficiently processed specific data types, demonstrating advanced knowledge in template specialization.
- **Inheritance Among Templated Classes**: Utilized inheritance to derive new templated classes from existing ones, enhancing code reusability and maintainability.

## Skills Gained

- **Advanced C++ Programming**: Gained proficiency in modern C++ (C++17), focusing on the use of templates to create flexible and efficient software components.
- **Software Testing and Debugging**: Applied rigorous testing methodologies using G++ compilers and Valgrind to ensure the development of robust and error-free applications.
- **Problem Solving**: Developed critical problem-solving skills by addressing challenges related to template specialization and memory management in C++.

## Compilation and Execution

To compile the project, use the following command:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```
Run the compiled application as follows to check for possible memory leaks:

```
valgrind ./ws
```


