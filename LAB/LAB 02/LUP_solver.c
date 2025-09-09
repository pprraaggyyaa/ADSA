#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function for LUP Decomposition
void LUPDecomposition(int n, float A[n][n], float L[n][n], float U[n][n], float P[n][n]) {
    int i, j, k;

    // Initialize L, U, P
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            L[i][j] = (i == j) ? 1 : 0;
            U[i][j] = A[i][j];
            P[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Gaussian elimination with partial pivoting
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

// Forward substitution for Ly = Pb
void forwardSubstitution(int n, float L[n][n], float Pb[n], float y[n]) {
    for (int i = 0; i < n; i++) {
        y[i] = Pb[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
}

// Back substitution for Ux = y
void backSubstitution(int n, float U[n][n], float y[n], float x[n]) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main() {
    int n;
    printf("Enter the order of the matrix (n): ");
    scanf("%d", &n);

    float A[n][n], L[n][n], U[n][n], P[n][n];
    float b[n], Pb[n], y[n], x[n];

    // Input matrix A
    printf("Enter the elements of matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Input vector b
    printf("Enter the elements of vector b (%d values):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Perform LUP Decomposition
    LUPDecomposition(n, A, L, U, P);

    // Compute Pb = P * b
    for (int i = 0; i < n; i++) {
        Pb[i] = 0;
        for (int j = 0; j < n; j++) {
            Pb[i] += P[i][j] * b[j];
        }
    }

    // Solve Ly = Pb
    forwardSubstitution(n, L, Pb, y);

    // Solve Ux = y
    backSubstitution(n, U, y, x);

    // Print solution
    printf("\nSolution vector x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %8.3f\n", i, x[i]);
    }

    return 0;
}
