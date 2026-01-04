# Kruskal’s Algorithm – Minimum Spanning Tree

## Aim
To find the **Minimum Spanning Tree (MST)** of a connected weighted graph
using **Kruskal’s Algorithm**.

## Description
This program implements **Kruskal’s Algorithm**, which is a **greedy algorithm**
used to find the Minimum Spanning Tree of a graph.

The graph is represented using an **adjacency matrix**.  
The algorithm repeatedly selects the **minimum weight edge** and checks whether
adding it to the MST forms a cycle. Cycle detection is handled using the
**Union–Find (Disjoint Set)** technique.

Edges are added until the MST contains **(n − 1)** edges.

## Algorithm Used
- Kruskal’s Algorithm
- Union–Find (Disjoint Set)

## Input
- Number of vertices `n`
- Adjacency matrix of the graph  
  (`0` indicates no edge)

## Output
- Edges included in the Minimum Spanning Tree
- Total minimum cost of the MST

## Data Structures Used
- Arrays
- Adjacency Matrix
- Disjoint Set (Union–Find)

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(E log E)** (conceptually, due to edge sorting)  
- In this implementation (using adjacency matrix): **O(V²)**

## Applications
- Network design
- Minimum cost connectivity
- Cable and road layout planning
- Graph optimization problems

## Conclusion
Kruskal’s Algorithm efficiently constructs a Minimum Spanning Tree by
selecting edges in increasing order of weight while avoiding cycles using
the Union–Find technique.

