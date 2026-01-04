# Splay Tree Implementation

## Aim
To implement a **Splay Tree**, a self-adjusting binary search tree,
and perform insertion with splaying.

## Description
This program implements a **Splay Tree**, which is a type of
self-adjusting binary search tree.

After every access or insertion, the accessed node is moved to the
root of the tree using **splay operations**. This helps frequently
accessed elements to be accessed faster in future operations.

The program supports:
- Insertion of elements
- Splaying using rotations
- Inorder traversal to display the tree contents

## Operations Used
- Right Rotation
- Left Rotation
- Splay Operation
- Insert Operation

## Input
- Number of nodes
- Elements to be inserted into the splay tree

## Output
- Inorder traversal of the splay tree

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Amortized time complexity for operations: **O(log n)**

## Applications
- Caching systems
- Memory management
- Dynamic search operations

## Conclusion
Splay Trees improve access time for frequently used elements by
bringing them closer to the root through splaying, making them
efficient for dynamic access patterns.

