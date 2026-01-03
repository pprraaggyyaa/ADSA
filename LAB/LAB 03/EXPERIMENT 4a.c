/* AVL Tree implementation in C
   Supports: insert, delete, inorder traversal, preorder traversal
   Compile: gcc avl.c -o avl
   Run: ./avl
*/

#include <stdio.h>
#include <stdlib.h>

/* AVL tree node */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

/* Utility: max of two ints */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Get height of node */
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

/* Create a new node */
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return node;
}

/* Right rotate subtree rooted with y */
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

/* Left rotate subtree rooted with x */
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

/* Get balance factor of node N */
int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/* Insert a key into the AVL tree and return new root */
Node* insert(Node* node, int key) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor to check whether this node became unbalanced */
    int balance = getBalance(node);

    // If unbalanced, there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Find node with minimum key value in tree rooted at node */
Node* minValueNode(Node* node) {
    Node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}

/* Delete a key and return new root */
Node* deleteNode(Node* root, int key) {
    // STEP 1: standard BST delete
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than root's key,
    // then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than root's key,
    // then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then this is the node to be deleted
    else {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) ) {
            Node *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else {
            // node with two children: get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: update height
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: get the balance factor
    int balance = getBalance(root);

    // If node is unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* A utility function to print preorder traversal of the tree.
   The function also prints height of every node */
void preOrder(Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Inorder traversal (sorted order) */
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

/* Main: simple menu-driven example */
int main() {
    Node *root = NULL;
    int choice, val;
    printf("AVL Tree Demo (insert/delete/inorder/preorder)\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            // clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) == 1) {
                    root = insert(root, val);
                    printf("%d inserted.\n", val);
                } else {
                    printf("Invalid value.\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) == 1) {
                    root = deleteNode(root, val);
                    printf("%d deleted (if it existed).\n", val);
                } else {
                    printf("Invalid value.\n");
                    while (getchar() != '\n');
                }
                break;
            case 3:
                printf("Inorder: ");
                inOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting.\n");
                // free tree (optional) - skipping for brevity
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
