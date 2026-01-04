# Maximum Bipartite Matching Using DFS

## Aim
To find the **maximum matching in a bipartite graph** using a
**DFS-based approach**.

## Description
This program implements the **Maximum Bipartite Matching** problem where
vertices are divided into two disjoint sets **U** and **V**.

An edge between a vertex in set U and a vertex in set V indicates that the two
vertices can be matched. The goal is to find the maximum number of such matches
such that no vertex is matched more than once.

The algorithm uses **Depth First Search (DFS)** to find an augmenting path
for each vertex in set U.

## Algorithm Used
- Maximum Bipartite Matching
- DFS-based Augmenting Path Algorithm

## Input
- Number of vertices in set **U**
- Number of vertices in set **V**
- Adjacency matrix representing edges between U and V  
  (1 indicates an edge, 0 indicates no edge)

## Output
- Maximum number of possible matchings in the bipartite graph

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- **O(V × E)**  
where `V` is the number of vertices and `E` is the number of edges.

## Applications
- Job assignment problems
- Resource allocation
- Matching applicants to jobs
- Network flow problems

## Conclusion
The DFS-based bipartite matching algorithm efficiently finds the maximum
matching by repeatedly searching for augmenting paths, ensuring that the
largest possible number of valid matches is obtained.

