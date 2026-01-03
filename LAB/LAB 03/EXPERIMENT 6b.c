#include <stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[MAX][MAX];
    int n;

    printf("★ Kruskal’s Algorithm – Minimum Spanning Tree ★\n\n");

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    int edges = 0, a, b, u, v, min, mincost = 0;
    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d -> %d  cost = %d\n", a, b, min);
            mincost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}
