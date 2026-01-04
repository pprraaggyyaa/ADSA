# Solving System of Linear Equations Using LUP Decomposition

## Aim
To solve a system of linear equations **Ax = b** using
**LUP Decomposition with partial pivoting**.

## Description
This program performs **LUP Decomposition** of a square matrix `A` such that:

P × A = L × U

Where:
- **L** is a lower triangular matrix
- **U** is an upper triangular matrix
- **P** is a permutation matrix

After decomposition, the system of equations is solved in two steps:
1. **Forward substitution** to solve `Ly = Pb`
2. **Back substitution** to solve `Ux = y`

This approach improves numerical stability and efficiently solves
linear systems.

## Algorithm Used
- LUP Decomposition with Partial Pivoting
- Forward Substitution
- Back Substitution

## Input
- Order of the matrix `n`
- Elements of matrix `A (n × n)`
- Elements of vector `b`

## Output
- Solution vector `x` such that `Ax = b`

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Applications
- Solving systems of linear equations
- Matrix inversion
- Numerical and scientific computations

## Conclusion
LUP Decomposition provides a stable and efficient method for solving
systems of linear equations by breaking the problem into simpler
triangular matrix operations.

