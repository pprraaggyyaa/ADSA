# Binary Search Tree (BST) Operations

## Aim
To implement a **Binary Search Tree (BST)** and perform basic operations such as
**insertion**, **deletion**, and **tree traversals**.

## Description
This program implements a Binary Search Tree where:
- Left subtree contains values smaller than the root
- Right subtree contains values greater than the root

The program is **menu-driven**, allowing the user to:
- Insert elements into the BST
- Delete elements from the BST
- Display the BST using inorder, preorder, and postorder traversals

Deletion handles all cases:
- Node with no child
- Node with one child
- Node with two children (using inorder successor)

## Operations Implemented
- Insert a node
- Delete a node
- Inorder Traversal
- Preorder Traversal
- Postorder Traversal

## Input
- User’s choice from the menu
- Integer values for insertion or deletion

## Output
- BST elements displayed using different traversal methods

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Insertion: **O(h)**
- Deletion: **O(h)**
- Traversal: **O(n)**  
Where `h` is the height of the tree and `n` is the number of nodes.

## Applications
- Searching and sorting data
- Database indexing
- Symbol tables
- Memory management

## Conclusion
Binary Search Trees provide an efficient way to store and retrieve ordered data.
This program demonstrates core BST operations and traversal techniques clearly.

