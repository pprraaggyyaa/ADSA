#include <stdio.h>
int weigh(int coins[], int l1, int r1, int l2, int r2) {
    int sum1 = 0, sum2 = 0;
    for (int i = l1; i <= r1; i++) sum1 += coins[i];
    for (int j = l2; j <= r2; j++) sum2 += coins[j];

    if (sum1 < sum2) return -1;   
    else if (sum1 > sum2) return 1; 
    else 
        return 0;                
}


int findDefective(int coins[], int left, int right) {
    
    if (left == right) return left;

    int n = right - left + 1;
    int mid = left + (n / 2) - 1; // mid index for splitting

    // Compare left half and right half
    int result = weigh(coins, left, mid, mid + 1, mid + (n / 2));

    if (result == -1) {
        // Defective in left half
        return findDefective(coins, left, mid);
    } else if (result == 1) {
        // Defective in right half
        return findDefective(coins, mid + 1, mid + (n / 2));
    } else {
        // Both halves equal
        if (n % 2 == 1) {
            // Odd coin out exists
            int extra = right;
            // Compare extra with any known good coin (say left)
            if (coins[extra] < coins[left]) return extra;
        }
        // No defective coin
        return -1;
    }
}

int main() {
    // Example: 7 coins, one defective at index 5 (lighter)
    int coins[7] = {10, 10, 10, 10, 8, 10, 10};

    int n = 7;
    int index = findDefective(coins, 0, n - 1);

    if (index == -1)
        printf("No defective coin found\n");
    else
        printf("Defective coin is at index %d\n", index);

    return 0;
}
