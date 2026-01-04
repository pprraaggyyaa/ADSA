# Strassen’s Matrix Multiplication Algorithm

## Aim
To implement **Strassen’s Matrix Multiplication algorithm** for multiplying
two matrices efficiently using the **divide and conquer technique**.

## Description
This program multiplies two matrices using Strassen’s algorithm, which reduces
the number of multiplications compared to the conventional matrix multiplication
method.

Since Strassen’s algorithm works best with matrices of size **2ⁿ × 2ⁿ**,
the program pads the input matrices with zeros to the nearest power of two
before performing multiplication.

The final result is then extracted from the valid portion of the resultant matrix.

## Algorithm Used
- Strassen’s Matrix Multiplication
- Divide and Conquer

## Input
- Number of rows and columns of matrix A
- Elements of matrix A
- Number of rows and columns of matrix B
- Elements of matrix B

## Output
- Resultant matrix after multiplication (valid portion only)

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Strassen’s Algorithm: **O(n^log₂7)** ≈ **O(n^2.81)**

## Applications
- Large matrix multiplication
- Scientific and numerical computations
- Computer graphics and image processing

## Conclusion
Strassen’s algorithm improves the efficiency of matrix multiplication by
reducing the number of recursive multiplications. Padding ensures compatibility
with matrices of arbitrary dimensions.

