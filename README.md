# Shamir's Secret Sharing - Polynomial Constant Term Calculation


## Steps to Run the Code
```bash
> cd R21EF240_CATALOG_assessment
> g++ assessment.cpp
> ./a.out
```
## Solution Overview

This project implements a simplified version of Shamir's Secret Sharing algorithm by finding the constant term of an unknown polynomial using given roots. The roots are provided in a JSON format with different base encodings for their y-values. The solution utilizes Lagrange interpolation to calculate the constant term.

## Approach

1. **Reading Input**:
   - The input is provided in a JSON file, containing a set of points representing roots of the polynomial. Each point has an associated base for its y-value.

2. **Decoding Y Values**:
   - The y-values are encoded in different bases (e.g., binary, decimal, etc.). A function converts these base-encoded strings to decimal integers.

3. **Finding the Constant Term**:
   - The constant term \( c \) of the polynomial is computed using **Lagrange interpolation**. This method evaluates the polynomial at \( x = 0 \) using the decoded y-values and their corresponding x-values.

4. **Output**:
   - The program outputs the constant term \( c \) calculated from the provided polynomial roots.

## Usage

1. **Input Format**:
   - The input should be structured in a JSON file (`input.json`) with the following format:
     ```json
     {
         "keys": {
             "n": 4,
             "k": 3
         },
         "1": {
             "base": "10",
             "value": "4"
         },
         "2": {
             "base": "2",
             "value": "111"
         },
         "3": {
             "base": "10",
             "value": "12"
         },
         "6": {
             "base": "4",
             "value": "213"
         }
     }
     ```

2. **Building and Running**:
   - Compile the C++ program using a C++ compiler, ensuring you link against the **nlohmann/json** library for JSON parsing.
   - Run the executable and ensure the `input.json` file is present in the same directory.

## Dependencies

- C++11 or later
- nlohmann/json library for JSON parsing (can be included via `#include "json.hpp"`)

## Example

Upon running the program with the provided input format, it will decode the y-values and output the constant term \( c \) of the polynomial derived from the roots.


## Output 
Test Case 1 : ![image](https://github.com/user-attachments/assets/78a18d44-6dfc-46cc-8991-0d737368d384)

Test Case 2 : ![image](https://github.com/user-attachments/assets/ff950244-ef10-4e7e-b2fd-12d0504db1bd)

![image](https://github.com/user-attachments/assets/3b4131c1-5104-4a28-b430-a66d37ca0a02)


