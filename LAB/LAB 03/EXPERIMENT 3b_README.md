# Postfix Expression Evaluation Using Stack

## Aim
To evaluate a **postfix expression** using the **stack data structure**.

## Description
This program evaluates a postfix (Reverse Polish Notation) expression consisting
of **single-digit operands** and arithmetic operators.

The algorithm scans the postfix expression from left to right:
- If the symbol is an operand, it is pushed onto the stack
- If the symbol is an operator, the top two operands are popped from the stack,
  the operation is performed, and the result is pushed back onto the stack

The final value remaining on the stack is the result of the expression.

## Data Structure Used
- Stack (array implementation)

## Operators Supported
- `+`, `-`, `*`, `/`

## Input
- Postfix expression containing single-digit operands

## Output
- Result of the evaluated postfix expression

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(n)**  
where `n` is the length of the postfix expression.

## Applications
- Expression evaluation
- Compiler design
- Stack-based calculators

## Conclusion
Postfix expressions can be efficiently evaluated using stacks since operator
precedence and parentheses are not required during evaluation.

