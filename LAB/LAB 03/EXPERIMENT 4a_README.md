# AVL Tree Implementation

## Aim
To implement an **AVL Tree**, a self-balancing Binary Search Tree, and perform
operations such as **insertion**, **deletion**, and **tree traversals**.

## Description
This program implements an **AVL Tree**, which maintains balance after every
insertion and deletion operation.

An AVL Tree ensures that the **height difference (balance factor)** between
the left and right subtrees of any node is at most **1**.  
If the tree becomes unbalanced, **rotations** are performed to restore balance.

The program is **menu-driven** and supports:
- Insertion of nodes
- Deletion of nodes
- Inorder traversal
- Preorder traversal

## Rotations Used
- Right Rotation (LL case)
- Left Rotation (RR case)
- Left-Right Rotation (LR case)
- Right-Left Rotation (RL case)

## Input
- User’s menu choice
- Integer values for insertion or deletion

## Output
- Tree traversal results
- Confirmation messages for insert/delete operations

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Insertion: **O(log n)**
- Deletion: **O(log n)**
- Traversal: **O(n)**  
Where `n` is the number of nodes in the AVL tree.

## Applications
- Database indexing
- Memory management
- Search-intensive applications
- Balanced search trees

## Conclusion
AVL Trees maintain balance automatically using rotations, ensuring efficient
search, insertion, and deletion operations with logarithmic time complexity.

