/* Program to generate a graph from Simple Interaction Format (SIF)
   Author: ChatGPT
   Compile: gcc sif_graph.c -o sif_graph
   Run: ./sif_graph < input.sif
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME  50

// Node structure
typedef struct {
    char name[MAX_NAME];
} Node;

Node nodes[MAX_NODES];
int adj[MAX_NODES][MAX_NODES]; // adjacency matrix
int nodeCount = 0;

// Find index of node, add if not exists
int getNodeIndex(char *name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i].name, name) == 0)
            return i;
    }
    if (nodeCount < MAX_NODES) {
        strcpy(nodes[nodeCount].name, name);
        nodeCount++;
        return nodeCount - 1;
    }
    return -1; // error if exceeds
}

int main() {
    char src[MAX_NAME], relation[MAX_NAME], dest[MAX_NAME];

    printf("Reading SIF input (format: nodeA relation nodeB)...\n");

    // Read until EOF
    while (scanf("%s %s %s", src, relation, dest) == 3) {
        int u = getNodeIndex(src);
        int v = getNodeIndex(dest);

        // Undirected edge (can be modified for directed)
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nGraph generated successfully!\n");
    printf("Nodes (%d):\n", nodeCount);
    for (int i = 0; i < nodeCount; i++) {
        printf("%d: %s\n", i, nodes[i].name);
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%s -> ", nodes[i].name);
        for (int j = 0; j < nodeCount; j++) {
            if (adj[i][j])
                printf("%s ", nodes[j].name);
        }
        printf("\n");
    }

    return 0;
}
