# Prim’s Algorithm – Minimum Spanning Tree

## Aim
To find the **Minimum Spanning Tree (MST)** of a connected weighted graph
using **Prim’s Algorithm**.

## Description
This program implements **Prim’s Algorithm** to generate a Minimum Spanning Tree
from a given weighted graph.

The graph is represented using an **adjacency matrix**. The algorithm starts
from an initial vertex (vertex 0) and repeatedly selects the **minimum weight
edge** that connects a visited vertex to an unvisited vertex.

The selected edges form the Minimum Spanning Tree, and their total weight gives
the minimum cost.

## Algorithm Used
- Prim’s Algorithm (Greedy Approach)

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

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(V²)**  
where `V` is the number of vertices (using adjacency matrix)

## Applications
- Network design
- Cable and road layout planning
- Minimum cost connectivity problems

## Conclusion
Prim’s Algorithm efficiently constructs a Minimum Spanning Tree by greedily
selecting the least costly edges, ensuring minimum total weight for connecting
all vertices in the graph.

