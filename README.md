# University Enrollment System
# CSS 342 Winter 2023
## Aisha Maabreh & Maryam Maabreh
2023win342d-p5-MaryamM4 created by GitHub Classroom

## Overview
This project implements an enrollment system for a university. It allows for the management of students, courses, and their enrollments. The system supports adding universities, reading student and course data from files, enrolling students in courses, and retrieving class lists sorted by student names or IDs.


## Files
Main Program (main.cpp):
- Contains the main function and test cases to verify the functionality of the enrollment system.
- Uses the EnrollmentSystem class to manage universities, students, and courses.
- Calls functions to read data from files and perform various operations like adding universities, enrolling students, and retrieving class lists.

Enrollment System (enrollmentsystem.cpp, enrollmentsystem.h):
- Manages multiple universities and provides an interface for the main program.
- Provides functions to add universities, set the current university, read student and course data from files, and perform enrollment operations.
- Interacts with the University class to delegate tasks related to students and courses.

University (university.cpp, university.h):
- Manages students and courses within a university.
- Provides functions to read student and course data, enroll students in courses, and retrieve class lists.
- Interacts with the Student and Course classes to manage their details and relationships.

Course (course.cpp, course.h):
- Manages course details and enrolled students.
- It includes methods for adding/removing students, checking if a student is enrolled, and retrieving class lists sorted by student names or IDs.
- Interacts with the Student class to manage student enrollments.

Student (student.cpp, student.h):
- Manages student details and enrolled courses.
- Provides functions to add and remove courses, check if a student is enrolled in a course, and retrieve student information.
- Interacts with the Course class to manage course enrollments.

Data Files
- data-courses.txt: Contains a list of courses with their IDs and titles.
- data-students.txt: Contains a list of students with their IDs, first names, and last names.
- data-enrollments.txt: Contains enrollment information, mapping student IDs to course IDs.
Scripts
- check-code-coverage.sh: Compiles the program with code coverage flags and generates a coverage report.
- create-output.sh: Compiles the program, runs it, and generates an output file with compilation warnings, program output, clang-tidy warnings, clang-format warnings, memory leak issues, and code coverage information.
- runit.sh: Compiles and runs the program.
Configuration Files
- .clang-format: Configuration file for clang-format, specifying code formatting rules.
- .clang-tidy: Configuration file for clang-tidy, specifying code analysis checks and options.
- .gitignore: Specifies files and directories to be ignored by Git.
- .vscode/c_cpp_properties.json: Configuration file for Visual Studio Code C++ properties.
- .vscode/launch.json: Configuration file for launching the program in Visual Studio Code.
- .vscode/settings.json: Configuration file for Visual Studio Code settings.
- .vscode/tasks.json: Configuration file for tasks in Visual Studio Code.
Output Files
- output.txt: Contains the output generated by running create-output.sh.

## Technical Details
The project is written in C++ and uses standard libraries for file I/O, string manipulation, and data structures.
The EnrollmentSystem class manages multiple universities and provides an interface for the main program.
The University class manages students and courses within a university.
The Course class manages course details and enrolled students.
The Student class manages student details and enrolled courses.
Data is read from text files and stored in appropriate data structures (e.g., maps) for efficient access and manipulation.
The project includes scripts for compiling, running, and generating code coverage reports.
Configuration files are provided for code formatting, code analysis, and Visual Studio Code settings.

## Usage
1. Compile the Program:
```
EnrollmentSystem es;
es.addUniversity("UWB");
```
Use the provided runit.sh script to compile and run the program:
2. Run the Program:
```
./runit.sh
```
After compilation, the program can be executed directly:
3. Test the Program:
```
./a.out
```
The main.cpp file contains test cases that verify the functionality of the enrollment system. Running the program will execute these tests and output the results.
4. Generate Code Coverage Report:
```
./check-code-coverage.sh
```
Use the check-code-coverage.sh script to compile the program with code coverage flags and generate a coverage report:
5. Create Output File:
```
./create-output.sh > output.txt 2>&1
```
Use the create-output.sh script to compile the program, run it, and generate an output file with various information such as compilation warnings, program output, clang-tidy warnings, clang-format warnings, memory leak issues, and code coverage information:
6. Debugging:
Use the provided launch.json configuration to debug the program in Visual Studio Code. Set breakpoints and run the debugger to step through the code.

### Example Workflow
Add a University:
```cpp
EnrollmentSystem es;
es.addUniversity("UWB");
```
Set Current University:
```cpp
es.setCurrentUniversity("UWB");
```
Read Data Files:
```cpp
es.readCourseList("data-courses.txt");
es.readStudentList("data-students.txt");
es.readEnrollmentInfo("data-enrollments.txt");
```
Enroll a Student in a Course:
```cpp
es.addCourse(1070, "CSS342");
```
Retrieve Class List:
```cpp
string classList = es.getClassListByLastName("CSS342");
cout << classList << endl;
```
Check Enrollment:
```cpp
bool isEnrolled = es.isInCourse(1070, "CSS342");
cout << (isEnrolled ? "Enrolled" : "Not Enrolled") << endl;
```
