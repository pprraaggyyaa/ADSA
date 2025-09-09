#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void LUPDecomposition(int n, float A[n][n], float L[n][n], float U[n][n], float P[n][n]) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = (i == j) ? 1 : 0;
            U[i][j] = A[i][j];
            P[i][j] = (i == j) ? 1 : 0;
        }
    }

    for (k = 0; k < n - 1; k++) {
        float max = 0;
        int pivot = k;

        for (i = k; i < n; i++) {
            if (fabs(U[i][k]) > max) {
                max = fabs(U[i][k]);
                pivot = i;
            }
        }

        if (pivot != k) {
            for (j = 0; j < n; j++) {
                float temp = U[k][j];
                U[k][j] = U[pivot][j];
                U[pivot][j] = temp;

                temp = P[k][j];
                P[k][j] = P[pivot][j];
                P[pivot][j] = temp;

                if (j < k) {
                    temp = L[k][j];
                    L[k][j] = L[pivot][j];
                    L[pivot][j] = temp;
                }
            }
        }

        if (U[k][k] == 0) {
            printf("Error: Singular matrix detected.\n");
            exit(1);
        }

        for (i = k + 1; i < n; i++) {
            L[i][k] = U[i][k] / U[k][k];
            for (j = k; j < n; j++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }
    }
}

void printMatrix(int n, float M[n][n], const char *name) {
    printf("\n%s Matrix:\n", name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the order of the matrix (n): ");
    scanf("%d", &n);

    float A[n][n], L[n][n], U[n][n], P[n][n];

    printf("Enter the elements of the matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    LUPDecomposition(n, A, L, U, P);

    printMatrix(n, L, "L");
    printMatrix(n, U, "U");
    printMatrix(n, P, "P");

    return 0;
}
