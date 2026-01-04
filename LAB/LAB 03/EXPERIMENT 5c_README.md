# Floyd–Warshall Algorithm – All Pairs Shortest Path

## Aim
To find the **shortest paths between all pairs of vertices** in a weighted graph
using the **Floyd–Warshall algorithm**.

## Description
This program implements the **Floyd–Warshall algorithm**, which computes the
shortest distances between every pair of vertices in a graph.

The algorithm works by gradually allowing each vertex to act as an
**intermediate vertex** and updating the shortest distance matrix accordingly.

The graph is represented using an **adjacency matrix**, where a large value
(`INF`) represents the absence of a direct edge between vertices.

## Algorithm Used
- Floyd–Warshall Algorithm
- Dynamic Programming approach

## Input
- Number of vertices `n`
- Adjacency matrix of the graph  
  (`INF` represents no direct edge)

## Output
- All Pairs Shortest Path distance matrix

## Data Structures Used
- 2D Arrays
- Adjacency Matrix

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(V³)**  
where `V` is the number of vertices.

## Applications
- Network routing
- Traffic optimization
- Graph analysis
- Shortest path problems in dense graphs

## Advantages
- Finds shortest paths between **all pairs of vertices**
- Works with **negative edge weights** (no negative cycles)

## Limitation
- Does not work if the graph contains **negative cycles**
- High time complexity for large graphs

## Conclusion
The Floyd–Warshall algorithm efficiently computes all-pairs shortest paths
using dynamic programming and is suitable for dense graphs with a small
number of vertices.

