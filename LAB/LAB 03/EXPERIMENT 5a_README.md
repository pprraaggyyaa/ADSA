# Graph Generation from Simple Interaction Format (SIF)

## Aim
To generate a **graph** from data given in **Simple Interaction Format (SIF)**
and represent it using an **adjacency matrix** and **adjacency list**.

## Description
This program reads graph input in **SIF format**, where each line represents
an interaction between two nodes in the form:

nodeA  relation  nodeB

The program:
- Assigns a unique index to each node
- Stores connections using an adjacency matrix
- Displays the graph as both an adjacency matrix and an adjacency list

The graph is treated as **undirected**, but it can be modified to work as
a directed graph if required.

## Input Format
- Input is read from standard input (until EOF)
- Each line follows the format:

Example:
A interacts B
B interacts C
A interacts C


## Output
- List of nodes with indices
- Adjacency matrix representation
- Adjacency list representation

## Data Structures Used
- Arrays
- Adjacency Matrix
- Adjacency List (derived from matrix)

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program with SIF input:

## Time Complexity
- Node lookup: **O(n)**
- Graph construction: **O(n²)** (using adjacency matrix)

## Applications
- Network analysis
- Bioinformatics interaction networks
- Graph visualization preprocessing
- Social network modeling

## Conclusion
This program demonstrates how structured text input in SIF format can be
converted into graph representations, making it useful for graph analysis
and visualization tasks.

