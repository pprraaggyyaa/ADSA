#include <stdio.h>
#include <stdlib.h>

// Structure of Splay Tree node
struct node {
    int key;
    struct node *left, *right;
};

// Right rotation
struct node* rightRotate(struct node* x) {
    struct node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
struct node* splay(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree
    if (key < root->key) {
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else {
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Insert function
struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    root = splay(root, key);

    if (root->key == key)
        return root;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    int n, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Inorder Traversal of Splay Tree: ");
    inorder(root);

    return 0;
}
