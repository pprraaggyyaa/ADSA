#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 9999

int main() {
    int cost[MAX][MAX], visited[MAX] = {0};
    int n, edges = 1, mincost = 0;

    // Example Graph (SIF-style data can be loaded here)
    // Adjust 'n' and cost matrix as per your graph
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    visited[0] = 1; // start from vertex 0
    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -> %d  cost = %d\n", u, v, min);
            visited[v] = 1;
            mincost += min;
            edges++;
        }
        cost[u][v] = cost[v][u] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}
