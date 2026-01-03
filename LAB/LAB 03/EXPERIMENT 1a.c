#include <stdio.h>

// Non-Recursive Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) 
        return -1; // Not found

    int mid = (low + high) / 2;

    if (arr[mid] == key) 
        return mid;
    else if (arr[mid] > key) 
        return binarySearchRecursive(arr, low, mid - 1, key);
    else 
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int arr[50], n, key, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    // Iterative Search
    pos = binarySearchIterative(arr, n, key);
    if (pos != -1)
        printf("Iterative: Element %d found at index %d\n", key, pos);
    else
        printf("Iterative: Element %d not found\n", key);

    // Recursive Search
    pos = binarySearchRecursive(arr, 0, n - 1, key);
    if (pos != -1)
        printf("Recursive: Element %d found at index %d\n", key, pos);
    else
        printf("Recursive: Element %d not found\n", key);

    return 0;
}

