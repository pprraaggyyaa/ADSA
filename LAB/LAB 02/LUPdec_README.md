# LUP Decomposition of a Matrix

## Aim
To implement **LUP Decomposition** of a given square matrix and obtain the
**Lower triangular matrix (L)**, **Upper triangular matrix (U)**, and
**Permutation matrix (P)**.

## Description
This program performs LUP Decomposition of a square matrix using **partial pivoting**.
The matrix `A` is decomposed such that:

P × A = L × U

Where:
- **L** is a lower triangular matrix with diagonal elements equal to 1
- **U** is an upper triangular matrix
- **P** is a permutation matrix representing row exchanges

Partial pivoting is used to improve numerical stability and avoid division by zero.

## Algorithm Used
- LUP Decomposition with Partial Pivoting

## Input
- Order of the matrix `n`
- Elements of the square matrix `A (n × n)`

## Output
- Lower triangular matrix `L`
- Upper triangular matrix `U`
- Permutation matrix `P`

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Applications
- Solving systems of linear equations
- Matrix inversion
- Numerical analysis and scientific computing

## Conclusion
LUP Decomposition efficiently decomposes a matrix into triangular and permutation
matrices, making it useful for solving linear systems and improving numerical stability.

