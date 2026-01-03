#include <stdio.h>

// Function to perform Strassen's multiplication on 2x2 matrices
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;

    M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    M2 = (A[1][0] + A[1][1]) * B[0][0];
    M3 = A[0][0] * (B[0][1] - B[1][1]);
    M4 = A[1][1] * (B[1][0] - B[0][0]);
    M5 = (A[0][0] + A[0][1]) * B[1][1];
    M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[2][2], B[2][2], C[2][2];
    int i, j;

    printf("Enter elements of first 2x2 matrix (A):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second 2x2 matrix (B):\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C);

    printf("\nResultant matrix after multiplication (C = A x B):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}
