# Simplex Method for Solving Linear Programming Problems

## Aim
To solve a **Linear Programming Problem (LPP)** using the **Simplex Method**
and find the optimal values of decision variables.

## Description
This program implements the **Simplex algorithm** to solve a maximization
problem subject to linear constraints.

The problem is first converted into a **simplex tableau** by introducing
slack variables. The algorithm then iteratively performs pivot operations
until an optimal solution is reached.

At each iteration:
- A pivot column is selected from the objective function row
- A pivot row is selected using the minimum ratio test
- Row operations are performed to update the tableau

The final tableau gives the **maximum value of the objective function**
and the values of the decision variables.

## Problem Statement Used
Maximize:
Z = 3x₁ + 5x₂

Subject to:
- x₁ + 2x₂ ≤ 8  
- 3x₁ + 2x₂ ≤ 12  
- x₁ + x₂ ≤ 5  
- x₁, x₂ ≥ 0

## Algorithm Used
- Simplex Method

## Input
- The simplex table is initialized directly in the program

## Output
- Optimal value of the objective function `Z`
- Optimal values of decision variables `x₁`, `x₂`

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Depends on the number of variables and constraints
- Polynomial time per iteration

## Applications
- Resource allocation problems
- Production planning
- Transportation and scheduling problems
- Operations research

## Conclusion
The Simplex Method efficiently solves linear programming problems by moving
from one feasible solution to another until the optimal solution is obtained.

