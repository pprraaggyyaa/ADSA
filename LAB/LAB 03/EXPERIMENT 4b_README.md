# B-Tree Implementation

## Aim
To implement a **B-Tree** and perform fundamental operations such as
**insertion**, **deletion**, and **traversal**.

## Description
This program implements a **B-Tree** of minimum degree `t`.
A B-Tree is a self-balancing multi-way search tree commonly used in
databases and file systems.

In a B-Tree:
- Each node can have at most `2t − 1` keys
- Each internal node can have at most `2t` children
- All leaf nodes appear at the same level
- The tree remains balanced after insertions and deletions

The program is **menu-driven** and supports insertion, deletion,
and inorder traversal of the B-Tree.

## Minimum Degree
- `t = 3`
- Maximum keys per node = `2t − 1 = 5`

## Operations Implemented
- Insert a key into the B-Tree
- Delete a key from the B-Tree
- Traverse the B-Tree (in sorted order)

## Input
- User’s menu choice
- Integer keys for insertion or deletion

## Output
- B-Tree contents after operations
- Status messages for insertion and deletion

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Search: **O(log n)**
- Insertion: **O(log n)**
- Deletion: **O(log n)**  
Where `n` is the number of keys in the B-Tree.

## Applications
- Database indexing
- File systems
- Large-scale storage systems
- Disk-based data structures

## Conclusion
B-Trees efficiently maintain sorted data and ensure balanced height,
making them ideal for systems that require fast access to large datasets.

