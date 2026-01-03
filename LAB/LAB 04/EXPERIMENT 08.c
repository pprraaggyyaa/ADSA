#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find length of LCS using DP
int LCS(char X[], char Y[], int m, int n, char lcs[]) {
    int L[MAX][MAX];
    int i, j;

    // Build table
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Reconstruct LCS string
    int index = L[m][n];
    lcs[index] = '\0';
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

// Recursive helper to print all common subsequences
void printAllCommon(char X[], char Y[], int m, int n, char res[], int index) {
    if (m == 0 || n == 0) {
        res[index] = '\0';
        if (strlen(res) > 0)
            printf("%s\n", res);
        return;
    }

    if (X[m - 1] == Y[n - 1]) {
        res[index] = X[m - 1];
        printAllCommon(X, Y, m - 1, n - 1, res, index + 1);
    } else {
        printAllCommon(X, Y, m - 1, n, res, index);
        printAllCommon(X, Y, m, n - 1, res, index);
    }
}

int main() {
    char X[MAX], Y[MAX], lcs[MAX], res[MAX];

    printf("Enter first string: ");
    gets(X);
    printf("Enter second string: ");
    gets(Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = LCS(X, Y, m, n, lcs);
    printf("\nLength of LCS: %d\n", length);
    printf("Longest Common Subsequence: %s\n", lcs);

    printf("\nAll possible common subsequences:\n");
    printAllCommon(X, Y, m, n, res, 0);

    return 0;
}
