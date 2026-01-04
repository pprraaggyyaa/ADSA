# Infix to Postfix Conversion Using Stack

## Aim
To convert an **infix expression** into an equivalent **postfix expression**
using the **stack data structure**.

## Description
This program converts an infix expression (operators placed between operands)
into a postfix expression (operators placed after operands).

The conversion is performed using a stack to handle operators and parentheses
based on their **precedence** rules.

Operands are directly added to the postfix expression, while operators are
pushed to or popped from the stack according to their precedence.

## Data Structure Used
- Stack (using array implementation)

## Operators Supported
- `+`, `-`, `*`, `/`
- Parentheses `(` and `)`

## Input
- Infix expression (containing operands and operators)

## Output
- Equivalent postfix expression

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(n)**  
where `n` is the length of the infix expression.

## Applications
- Expression evaluation
- Compiler design
- Syntax parsing
- Arithmetic expression processing

## Conclusion
This program demonstrates how stacks can be effectively used to convert
infix expressions into postfix form by following operator precedence rules.

