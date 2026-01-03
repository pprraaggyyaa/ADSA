/* B-Tree implementation in C
   Supports: insert, delete, traversal
   Minimum degree = t
*/

#include <stdio.h>
#include <stdlib.h>

#define T 3  // Minimum degree (t). Each node can have at most 2*T - 1 keys

typedef struct BTreeNode {
    int keys[2*T - 1];       // An array of keys
    struct BTreeNode *C[2*T]; // An array of child pointers
    int n;                  // Current number of keys
    int leaf;               // Is true when node is leaf. Otherwise false
} BTreeNode;

BTreeNode* createNode(int leaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    for (int i = 0; i < 2*T; i++)
        newNode->C[i] = NULL;
    return newNode;
}

/* Traverses the tree in-order */
void traverse(BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                traverse(root->C[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
            traverse(root->C[i]);
    }
}

/* Search key in subtree rooted with root */
BTreeNode* search(BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (i < root->n && root->keys[i] == k)
        return root;

    if (root->leaf)
        return NULL;

    return search(root->C[i], k);
}

/* Splits the child y of node x at index i */
void splitChild(BTreeNode* x, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j+T];

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->C[j] = y->C[j+T];
    }

    y->n = T - 1;

    for (int j = x->n; j >= i+1; j--)
        x->C[j+1] = x->C[j];

    x->C[i+1] = z;

    for (int j = x->n-1; j >= i; j--)
        x->keys[j+1] = x->keys[j];

    x->keys[i] = y->keys[T-1];
    x->n = x->n + 1;
}

/* Insert a new key into non-full node */
void insertNonFull(BTreeNode* x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n = x->n + 1;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;

        if (x->C[i+1]->n == 2*T - 1) {
            splitChild(x, i+1, x->C[i+1]);
            if (k > x->keys[i+1])
                i++;
        }
        insertNonFull(x->C[i+1], k);
    }
}

/* Insert into B-Tree */
BTreeNode* insert(BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*T - 1) {
        BTreeNode* s = createNode(0);
        s->C[0] = root;
        splitChild(s, 0, root);
        int i = 0;
        if (s->keys[0] < k)
            i++;
        insertNonFull(s->C[i], k);
        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

/* Utility to get predecessor */
int getPred(BTreeNode* x, int idx) {
    BTreeNode* cur = x->C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

/* Utility to get successor */
int getSucc(BTreeNode* x, int idx) {
    BTreeNode* cur = x->C[idx+1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

/* Merge child y with sibling z */
void merge(BTreeNode* x, int idx) {
    BTreeNode* y = x->C[idx];
    BTreeNode* z = x->C[idx+1];

    y->keys[T-1] = x->keys[idx];

    for (int i = 0; i < z->n; ++i)
        y->keys[i+T] = z->keys[i];

    if (!y->leaf) {
        for (int i = 0; i <= z->n; ++i)
            y->C[i+T] = z->C[i];
    }

    for (int i = idx+1; i < x->n; ++i)
        x->keys[i-1] = x->keys[i];

    for (int i = idx+2; i <= x->n; ++i)
        x->C[i-1] = x->C[i];

    y->n += z->n + 1;
    x->n--;
    free(z);
}

/* Delete from node x at index idx */
void deleteFromNode(BTreeNode* x, int idx);

void deleteKey(BTreeNode** root, int k);

void fill(BTreeNode* x, int idx);

/* Delete key from B-Tree rooted at *root */
void deleteKey(BTreeNode** root, int k) {
    if (*root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    deleteFromNode(*root, k);

    if ((*root)->n == 0) {
        BTreeNode* tmp = *root;
        if ((*root)->leaf)
            *root = NULL;
        else
            *root = (*root)->C[0];
        free(tmp);
    }
}

/* Delete key at index idx */
void deleteFromNode(BTreeNode* x, int k) {
    int idx = 0;
    while (idx < x->n && x->keys[idx] < k)
        ++idx;

    if (idx < x->n && x->keys[idx] == k) {
        if (x->leaf) {
            for (int i = idx+1; i < x->n; ++i)
                x->keys[i-1] = x->keys[i];
            x->n--;
        } else {
            if (x->C[idx]->n >= T) {
                int pred = getPred(x, idx);
                x->keys[idx] = pred;
                deleteFromNode(x->C[idx], pred);
            } else if (x->C[idx+1]->n >= T) {
                int succ = getSucc(x, idx);
                x->keys[idx] = succ;
                deleteFromNode(x->C[idx+1], succ);
            } else {
                merge(x, idx);
                deleteFromNode(x->C[idx], k);
            }
        }
    } else {
        if (x->leaf) {
            printf("Key %d not found\n", k);
            return;
        }
        int flag = (idx == x->n);
        if (x->C[idx]->n < T)
            fill(x, idx);
        if (flag && idx > x->n)
            deleteFromNode(x->C[idx-1], k);
        else
            deleteFromNode(x->C[idx], k);
    }
}

/* Fill child C[idx] if it has less than T-1 keys */
void borrowFromPrev(BTreeNode* x, int idx);
void borrowFromNext(BTreeNode* x, int idx);

void fill(BTreeNode* x, int idx) {
    if (idx != 0 && x->C[idx-1]->n >= T)
        borrowFromPrev(x, idx);
    else if (idx != x->n && x->C[idx+1]->n >= T)
        borrowFromNext(x, idx);
    else {
        if (idx != x->n)
            merge(x, idx);
        else
            merge(x, idx-1);
    }
}

void borrowFromPrev(BTreeNode* x, int idx) {
    BTreeNode* child = x->C[idx];
    BTreeNode* sibling = x->C[idx-1];

    for (int i = child->n-1; i >= 0; --i)
        child->keys[i+1] = child->keys[i];

    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i+1] = child->C[i];
    }

    child->keys[0] = x->keys[idx-1];

    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    x->keys[idx-1] = sibling->keys[sibling->n-1];

    child->n += 1;
    sibling->n -= 1;
}

void borrowFromNext(BTreeNode* x, int idx) {
    BTreeNode* child = x->C[idx];
    BTreeNode* sibling = x->C[idx+1];

    child->keys[child->n] = x->keys[idx];

    if (!child->leaf)
        child->C[child->n+1] = sibling->C[0];

    x->keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i-1] = sibling->C[i];
    }

    child->n += 1;
    sibling->n -= 1;
}

/* Main program: simple menu */
int main() {
    BTreeNode* root = NULL;
    int choice, val;

    printf("B-Tree Demo (insert, delete, traverse)\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("%d inserted.\n", val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                deleteKey(&root, val);
                break;
            case 3:
                printf("B-Tree contents (inorder): ");
                traverse(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
