# EMPLOYEE-MANAGEMENT-SYSTEM-VIA-SORTING-C++



# Employee Management System (C++)

## Overview

This is a console-based Employee Management System developed in C++. The program allows users to manage employee records using a dynamic `vector` data structure. It supports adding, searching, deleting, displaying, and sorting employee information.

The project demonstrates the use of:

* Structures (`struct`)
* Functions
* Vectors (Dynamic Arrays)
* Searching Algorithms
* Selection Sort
* Merge Sort
* String Manipulation
* Menu-Driven Programming

---

## Features

### 1. Add Employee

Users can add employee details including:

* Employee ID
* Employee Name
* Phone Number
* Number of Years Worked
* Base Salary
* Increment Percentage

The system automatically calculates the employee's total salary.

### 2. Remove Last Employee

Removes the most recently added employee from the system.

### 3. Search Employee

Employees can be searched by:

* Name (case-insensitive)
* Phone Number
* Employee ID

### 4. Delete Employee

Employees can be deleted using:

* Name
* Phone Number
* Employee ID

### 5. Display All Employees

Displays employee records sorted in three different ways:

#### Alphabetical Order by Name

Uses a custom sorting function.

#### Ascending Order by Employee ID

Uses the Selection Sort algorithm.

#### Descending Order by Total Salary

Uses the Merge Sort algorithm.

---

## Salary Calculation

Total salary is calculated using the following formula:

```
Total Salary = Base Salary + (Base Salary × Increment Percentage ÷ 100 × Years Worked)
```

Example:

```
Base Salary = 50,000
Increment = 10%
Years Worked = 5

Total Salary = 50,000 + (50,000 × 10/100 × 5)
             = 75,000
```

---

## Data Structure

### Employee Structure

```cpp
struct Employee {
    string empID;
    string empName;
    string phoneNum;
    int numberOfYearsWorked;
    double baseSalary;
    double incrementPercent;
    double totalSalary;
};
```

---

## Sorting Algorithms Used

### Name Sorting

* Custom comparison
* Alphabetical order

### Employee ID Sorting

* Selection Sort
* Time Complexity: O(n²)

### Salary Sorting

* Merge Sort
* Time Complexity: O(n log n)

---

## Menu Options

```
1. Add Employee
2. Remove Last Employee
3. Search Name
4. Search Phone
5. Search ID
6. Delete Employee
7. Show All Employees
8. Exit
```

---

## Sample Output

```
1.Add Employee
2.Remove Last
3.Search Name
4.Search Phone
5.Search ID
6.Delete
7.Show All
8.Exit

Choice: 1

ID: E101
Name: John Smith
Phone: 01712345678
Number of Years Worked: 5
Base Salary: 50000
Increment %: 10

Employee added.
```

---

## Requirements

* C++11 or later
* GCC, MinGW, Code::Blocks, Dev-C++, Visual Studio, or any C++ compiler

---

## Learning Objectives

This project helps understand:

* Structures in C++
* Vectors and dynamic memory management
* Function design
* Searching techniques
* Selection Sort implementation
* Merge Sort implementation
* Menu-driven applications
* Case-insensitive string comparison

---

## Future Improvements

Possible enhancements include:

* File handling for data persistence
* Update employee information
* Multiple employee search results
* Validation for phone numbers and IDs
* Binary Search after sorting
* Graphical User Interface (GUI)
* Database integration

---

## Author
 SAIFUL SIDDIKY LABIB
Employee Management System Project

Developed in C++ as a demonstration of data structures, sorting algorithms, and employee record management.
