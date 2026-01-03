/* Floyd–Warshall Algorithm - All Pairs Shortest Path
   Author: ChatGPT
   Compile: gcc floyd.c -o floyd
   Run: ./floyd
*/

#include <stdio.h>

#define V 10         // Maximum number of vertices
#define INF 99999    // A large value to represent infinity

// Function to print the distance matrix
void printSolution(int dist[][V], int n) {
    printf("All Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V], int n) {
    int dist[V][V];

    // Initialize the solution matrix same as input graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one as intermediate
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, n);
}

int main() {
    int n;
    int graph[V][V];

    printf("Enter number of vertices (<= %d): ", V);
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for INF/no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}
