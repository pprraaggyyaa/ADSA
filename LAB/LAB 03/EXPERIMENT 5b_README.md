# Dijkstra’s Algorithm – Single Source Shortest Path

## Aim
To find the **shortest path distances** from a given **source vertex**
to all other vertices in a weighted graph using **Dijkstra’s Algorithm**.

## Description
This program implements **Dijkstra’s Algorithm** for a graph represented
using an **adjacency matrix**.

The algorithm works by:
- Initializing distances from the source to all vertices as infinity
- Repeatedly selecting the vertex with the minimum distance that is not
  yet included in the shortest path tree
- Updating distances of its adjacent vertices

The program outputs the shortest distance from the source vertex to
every other vertex in the graph.

## Algorithm Used
- Dijkstra’s Algorithm (Greedy Approach)

## Input
- Number of vertices `n`
- Adjacency matrix of the graph  
  (0 indicates no edge)
- Source vertex

## Output
- Shortest distance from the source vertex to all other vertices

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
- Network routing
- GPS and navigation systems
- Shortest path problems
- Graph-based optimization

## Limitations
- Does not work with **negative edge weights**

## Conclusion
Dijkstra’s Algorithm efficiently computes the shortest paths from a single
source vertex to all other vertices in a graph with non-negative edge weights.

