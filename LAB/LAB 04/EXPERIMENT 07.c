#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// Node structure
struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

// Min-Heap structure
struct minHeap {
    unsigned size;
    struct node* arr[MAX];
};

// Function to create new node
struct node* newNode(char data, unsigned freq) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Swap two nodes
void swap(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function
void heapify(struct minHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < (int)heap->size && heap->arr[l]->freq < heap->arr[smallest]->freq)
        smallest = l;
    if (r < (int)heap->size && heap->arr[r]->freq < heap->arr[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract minimum node
struct node* extractMin(struct minHeap* heap) {
    struct node* temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}

// Insert node in heap
void insertHeap(struct minHeap* heap, struct node* n) {
    int i = heap->size++;
    while (i && n->freq < heap->arr[(i - 1) / 2]->freq) {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arr[i] = n;
}

// Build Huffman Tree
struct node* buildHuffmanTree(char data[], int freq[], int size) {
    struct node *left, *right, *top;
    struct minHeap heap;
    heap.size = size;

    for (int i = 0; i < size; i++)
        heap.arr[i] = newNode(data[i], freq[i]);

    // Build initial min-heap
    for (int i = (heap.size - 1) / 2; i >= 0; i--)
        heapify(&heap, i);

    // Iterate until heap has one element
    while (heap.size > 1) {
        left = extractMin(&heap);
        right = extractMin(&heap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertHeap(&heap, top);
    }

    return extractMin(&heap);
}

// Print Huffman Codes
void printCodes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char str[100];
    int freq[MAX] = {0};
    char data[MAX];
    int f[MAX], size = 0;

    printf("Enter a string: ");
    gets(str);

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    for (int i = 0; i < MAX; i++) {
        if (freq[i]) {
            data[size] = (char)i;
            f[size] = freq[i];
            size++;
        }
    }

    struct node* root = buildHuffmanTree(data, f, size);

    int arr[100], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);

    return 0;
}

