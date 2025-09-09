#include <stdio.h>
#include <stdlib.h>

// Function to find the next power of two greater than or equal to n
int nextPowerOfTwo(int n) {
    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}

// Function to pad the matrix to target size with zeros
void padMatrix(int **orig, int **padded, int rows, int cols, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < rows && j < cols)
                padded[i][j] = orig[i][j];
            else
                padded[i][j] = 0;
        }
    }
}

// Function to print a matrix
void printMatrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrix(int **A, int **B, int **result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] + B[i][j];
}

// Function to subtract matrix B from A
void subtractMatrix(int **A, int **B, int **result, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] - B[i][j];
}

// Strassen's multiplication function
void strassen(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    // Allocate memory for submatrices
    int **A11 = malloc(newSize * sizeof(int *));
    int **A12 = malloc(newSize * sizeof(int *));
    int **A21 = malloc(newSize * sizeof(int *));
    int **A22 = malloc(newSize * sizeof(int *));
    int **B11 = malloc(newSize * sizeof(int *));
    int **B12 = malloc(newSize * sizeof(int *));
    int **B21 = malloc(newSize * sizeof(int *));
    int **B22 = malloc(newSize * sizeof(int *));
    int **M1 = malloc(newSize * sizeof(int *));
    int **M2 = malloc(newSize * sizeof(int *));
    int **M3 = malloc(newSize * sizeof(int *));
    int **M4 = malloc(newSize * sizeof(int *));
    int **M5 = malloc(newSize * sizeof(int *));
    int **M6 = malloc(newSize * sizeof(int *));
    int **M7 = malloc(newSize * sizeof(int *));
    int **AResult = malloc(newSize * sizeof(int *));
    int **BResult = malloc(newSize * sizeof(int *));

    for (int i = 0; i < newSize; i++) {
        A11[i] = malloc(newSize * sizeof(int));
        A12[i] = malloc(newSize * sizeof(int));
        A21[i] = malloc(newSize * sizeof(int));
        A22[i] = malloc(newSize * sizeof(int));
        B11[i] = malloc(newSize * sizeof(int));
        B12[i] = malloc(newSize * sizeof(int));
        B21[i] = malloc(newSize * sizeof(int));
        B22[i] = malloc(newSize * sizeof(int));
        M1[i] = malloc(newSize * sizeof(int));
        M2[i] = malloc(newSize * sizeof(int));
        M3[i] = malloc(newSize * sizeof(int));
        M4[i] = malloc(newSize * sizeof(int));
        M5[i] = malloc(newSize * sizeof(int));
        M6[i] = malloc(newSize * sizeof(int));
        M7[i] = malloc(newSize * sizeof(int));
        AResult[i] = malloc(newSize * sizeof(int));
        BResult[i] = malloc(newSize * sizeof(int));
    }

    // Divide matrices into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, AResult, newSize);
    addMatrix(B11, B22, BResult, newSize);
    strassen(AResult, BResult, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, AResult, newSize);
    strassen(AResult, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, BResult, newSize);
    strassen(A11, BResult, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, BResult, newSize);
    strassen(A22, BResult, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, AResult, newSize);
    strassen(AResult, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, AResult, newSize);
    addMatrix(B11, B12, BResult, newSize);
    strassen(AResult, BResult, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, AResult, newSize);
    addMatrix(B21, B22, BResult, newSize);
    strassen(AResult, BResult, M7, newSize);

    // Calculating C11, C12, C21, C22
    int **C11 = malloc(newSize * sizeof(int *));
    int **C12 = malloc(newSize * sizeof(int *));
    int **C21 = malloc(newSize * sizeof(int *));
    int **C22 = malloc(newSize * sizeof(int *));
    for (int i = 0; i < newSize; i++) {
        C11[i] = malloc(newSize * sizeof(int));
        C12[i] = malloc(newSize * sizeof(int));
        C21[i] = malloc(newSize * sizeof(int));
        C22[i] = malloc(newSize * sizeof(int));
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C11[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C12[i][j] = M3[i][j] + M5[i][j];
            C21[i][j] = M2[i][j] + M4[i][j];
            C22[i][j] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            if (i < newSize && j < newSize)
                C[i][j] = C11[i][j];
            if (i < newSize && j + newSize < size)
                C[i][j + newSize] = C12[i][j];
            if (i + newSize < size && j < newSize)
                C[i + newSize][j] = C21[i][j];
            if (i + newSize < size && j + newSize < size)
                C[i + newSize][j + newSize] = C22[i][j];
        }
    }

   
    for (int i = 0; i < newSize; i++) {
        free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
        free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
        free(M1[i]); free(M2[i]); free(M3[i]); free(M4[i]);
        free(M5[i]); free(M6[i]); free(M7[i]);
        free(AResult[i]); free(BResult[i]);
        free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
    }
    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(M1); free(M2); free(M3); free(M4);
    free(M5); free(M6); free(M7);
    free(AResult); free(BResult);
    free(C11); free(C12); free(C21); free(C22);
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &r1, &c1);

    int **A = malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        A[i] = malloc(c1 * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
        return 1;
    }

    int **B = malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++) {
        B[i] = malloc(c2 * sizeof(int));
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nOriginal Matrix A:\n");
    printMatrix(A, r1, c1);

    printf("Original Matrix B:\n");
    printMatrix(B, r2, c2);

    
    int max_dim = r1;
    if (c1 > max_dim) max_dim = c1;
    if (r2 > max_dim) max_dim = r2;
    if (c2 > max_dim) max_dim = c2;
    int size = nextPowerOfTwo(max_dim);

    int **A_pad = malloc(size * sizeof(int *));
    int **B_pad = malloc(size * sizeof(int *));
    int **C_pad = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        A_pad[i] = malloc(size * sizeof(int));
        B_pad[i] = malloc(size * sizeof(int));
        C_pad[i] = malloc(size * sizeof(int));
    }

    padMatrix(A, A_pad, r1, c1, size);
    padMatrix(B, B_pad, r2, c2, size);

    printf("Padded Matrix A:\n");
    printMatrix(A_pad, size, size);

    printf("Padded Matrix B:\n");
    printMatrix(B_pad, size, size);

    strassen(A_pad, B_pad, C_pad, size);

    printf("Resultant Matrix (only valid portion):\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%4d ", C_pad[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < r1; i++)
        free(A[i]);
    for (int i = 0; i < r2; i++)
        free(B[i]);
    for (int i = 0; i < size; i++) {
        free(A_pad[i]);
        free(B_pad[i]);
        free(C_pad[i]);
    }
    free(A);
    free(B);
    free(A_pad);
    free(B_pad);
    free(C_pad);

    return 0;
}