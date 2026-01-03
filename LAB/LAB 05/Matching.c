#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define M 100   // Maximum vertices in set U
#define N 100   // Maximum vertices in set V

// A DFS based recursive function that returns true if a matching for vertex u is possible
bool bpm(bool graph[M][N], int u, bool seen[], int matchR[], int n)
{
    for (int v = 0; v < n; v++)
    {
        // If there is an edge from u to v and v is not seen before
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If v is not matched or previously matched vertex
            // can be reassigned
            if (matchR[v] < 0 || bpm(graph, matchR[v], seen, matchR, n))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching
int maxBPM(bool graph[M][N], int m, int n)
{
    // matchR[v] = u means vertex v in set V is matched with vertex u in set U
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));

    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < m; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        if (bpm(graph, u, seen, matchR, n))
            result++;
    }
    return result;
}

int main()
{
    int m, n;
    printf("Enter number of vertices in set U: ");
    scanf("%d", &m);
    printf("Enter number of vertices in set V: ");
    scanf("%d", &n);

    bool graph[M][N];
    printf("Enter adjacency matrix (0 or 1):\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int max_matching = maxBPM(graph, m, n);
    printf("Maximum number of matchings: %d\n", max_matching);

    return 0;
}
