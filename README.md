# C++ Exercises

---

## Module 05

* **Exercise 00** (Mommy, when I grow up, I want to be a bureaucrat!): Introduces a `Bureaucrat` class with a constant name and a grade between 1 (highest) and 150 (lowest).
It requires proper exception handling for out-of-range grades and provides increment/decrement functions, getters, and a custom << operator overload for printing.

* **Exercise 01** (Form up, maggots!): Adds a `Form` class with a name, signed status, and required grades to sign/execute it.
Bureaucrats attempt to sign forms via `beSigned()`, which checks their grade and may throw an exception; the `signForm()` function in `Bureaucrat` handles this and prints the result.

* **Exercise 02** (No, you need form 28B, not 28C...): Refines the form system by making `AForm` an abstract base class with concrete forms `ShrubberyCreationForm`, `RobotomyRequestForm` and `PresidentialPardonForm` that implement specific actions.
Bureaucrats can execute forms if they are signed and the bureaucrat’s grade is sufficient, otherwise exceptions are thrown.
Execution status and errors are printed by the bureaucrat’s `executeForm()` function.

* **Exercise 03** (At least this beats coffee-making): Implements an `Intern` class whose key role is to create forms dynamically via its `makeForm()` method based on a form name and target.
It returns a pointer to the appropriate `AForm` subclass, printing a creation message or an error if the form name is invalid.
The solution should avoid long if-else chains, favoring clean, maintainable code.

---

## Module 06

* **Exercise 00** (Conversion of scalar types): Implements a `ScalarConverter` class with a static convert method that takes a string literal and converts it to char, int, float, and double types.
It detects the input type, handles special pseudo-literals (like nan, inf), and prints conversion results or error messages if conversion is impossible or non-displayable.
The class is non-instantiable and includes thorough testing for various literal inputs.

* **Exercise 01** (Serialization): Implements a `Serializer` class with static methods to convert a pointer to an integer (serialize) and back (deserialize).
It tests that serializing a pointer to a `Data` object and then deserializing it returns the original pointer.
The `Data` structure must contain some data members to validate correct serialization and deserialization.

* **Exercise 02** (Identify real type): Implements a `Base` class with three derived classes `A`, `B` and `C` and functions to randomly create one of them.
It identifies the actual derived type of an object via a pointer or reference without using typeinfo.
The goal is to practice runtime type identification manually and test that the functions correctly print the real type.

* **Exercise 03** (): 

---

## Module 07

* **Exercise 00** (Start with a few functions): Implements three function templates: `swap` to exchange two values, `min` to return the smaller of two values (returning the second if equal), and `max` to return the larger (also returning the second if equal).
These templates work with any type that supports comparison operators.
The functions must be defined in header files.

* **Exercise 01** (Iter): Implements a function template `iter` that applies a given function to each element of an array.
It takes three parameters: a pointer to the array, the array length, and the function to apply to each element.
The `iter` template must work with any array type.

* **Exercise 02** (Array): Creates a class template `Array` that manages a dynamic array of elements of type `T`.
It supports default and sized constructors, deep copy and assignment, safe element access with bounds checking (throwing exceptions if out of range), and a `size()` method to get the array length.
Memory must be dynamically allocated with `new[]`, ensuring independent copies after assignment or copy construction.

---

## Module 08

* **Exercise 00** (Easy find): Has a function template `easyfind` that searches for the first occurrence of an integer value within a container of integers.
If the value is found, it returns an iterator or equivalent; otherwise, it throws an exception or returns an error.
It must work with standard-like containers (not associative ones).

* **Exercise 01** (Span): Creates a `Span` class that stores up to N integers and can add numbers individually or in bulk via iterators.
It provides functions to find the shortest and longest distance (span) between stored numbers, throwing exceptions if there aren't enough numbers.

* **Exercise 02** (Mutated abomination): Creates a `MutantStack` class that extends `std::stack` by adding iterator support, making the stack iterable.
It keeps all `std::stack` functionalities while allowing iteration through elements like other containers.
You also implement tests to verify that iterating over `MutantStack` behaves like iterating over a standard container such as `std::list`.

---

## Module 09

* **Exercise 00** (Bitcoin Exchange): This program reads a CSV database of historical Bitcoin prices by date and processes an input file with dates and amounts.
For each input line, it calculates and prints the value of the specified amount of Bitcoin on that date, using the closest earlier date in the database if the exact date is missing.
It also validates inputs and prints error messages for invalid dates or amounts.

* **Exercise 01** (Reverse Polish Notation): This program evaluates a Reverse Polish Notation (RPN) expression passed as a command-line argument using a container (`std::stack`).
It supports basic arithmetic operations (+, -, *, /) on single-digit integers.
It prints the result or an error message if the expression is invalid.

* **Exercise 02** (PmergeMe): This program takes a list of positive integers as input and sorts them using the Ford-Johnson (merge-insert) algorithm.
It must use two different containers (`std::vector` and `std::list`) and measure the time each one takes.
It prints the unsorted and sorted sequences along with timing results for both containers.
