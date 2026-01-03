#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printTable(float table[MAX][MAX], int m, int n) {
    printf("\n--------------------------------------------------\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%8.2f", table[i][j]);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}

int main() {
    int m = 3; // Number of constraints
    int n = 2; // Number of variables

    // Example Problem:
    // Maximize Z = 3x1 + 5x2
    // Subject to:
    //  x1 + 2x2 <= 8
    //  3x1 + 2x2 <= 12
    //  x1 + x2 <= 5
    //  and x1, x2 >= 0

    float table[MAX][MAX] = {
        {1, 2, 1, 0, 0, 8},
        {3, 2, 0, 1, 0, 12},
        {1, 1, 0, 0, 1, 5},
        {-3, -5, 0, 0, 0, 0}  // Objective function row
    };

    int rows = m + 1;       // Constraints + objective row
    int cols = n + m + 1;   // Variables + slack + RHS
    int i, j, pivot_row, pivot_col;
    float min, ratio, pivot;

    printf("Initial Simplex Table:\n");
    printTable(table, rows, cols);

    while (1) {
        // Step 1: Find pivot column (most negative in last row)
        pivot_col = -1;
        min = 0;
        for (j = 0; j < cols - 1; j++) {
            if (table[rows - 1][j] < min) {
                min = table[rows - 1][j];
                pivot_col = j;
            }
        }
        if (pivot_col == -1)
            break; // Optimal solution found

        // Step 2: Find pivot row (minimum positive ratio)
        pivot_row = -1;
        float min_ratio = 99999;
        for (i = 0; i < rows - 1; i++) {
            if (table[i][pivot_col] > 0) {
                ratio = table[i][cols - 1] / table[i][pivot_col];
                if (ratio < min_ratio) {
                    min_ratio = ratio;
                    pivot_row = i;
                }
            }
        }

        if (pivot_row == -1) {
            printf("\nUnbounded Solution!\n");
            return 0;
        }

        // Step 3: Pivot element
        pivot = table[pivot_row][pivot_col];

        // Step 4: Normalize pivot row
        for (j = 0; j < cols; j++)
            table[pivot_row][j] /= pivot;

        // Step 5: Eliminate pivot column from other rows
        for (i = 0; i < rows; i++) {
            if (i != pivot_row) {
                float factor = table[i][pivot_col];
                for (j = 0; j < cols; j++)
                    table[i][j] -= factor * table[pivot_row][j];
            }
        }

        printf("\nAfter iteration:\n");
        printTable(table, rows, cols);
    }

    printf("\n✅ Optimal solution found!\n");
    printf("Maximum value of Z = %.2f\n", table[rows - 1][cols - 1]);

    // Find variable values
    float x_values[MAX] = {0};
    for (j = 0; j < n; j++) { // only for x1, x2,...
        int one_count = 0, one_row = -1;
        for (i = 0; i < m; i++) {
            if (table[i][j] == 1)
                one_count++, one_row = i;
            else if (table[i][j] != 0)
                one_count = -99;
        }
        if (one_count == 1)
            x_values[j] = table[one_row][cols - 1];
        else
            x_values[j] = 0;
    }

    printf("\nVariable values:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.2f\n", i + 1, x_values[i]);

    return 0;
}
