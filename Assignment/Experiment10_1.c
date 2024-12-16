#include <stdio.h>
#include <stdlib.h>

// Define a node for the AVL tree
typedef struct Node {
    int key;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Helper function to get the balance factor of a node
int get_balance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Create a new node
Node* create_node(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->height = 1; // New node is initially added at height 1
    node->left = node->right = NULL;
    return node;
}

// Perform a right rotation
Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Perform a left rotation
Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    if (!node) return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = get_balance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Find the node with the smallest key in a tree
Node* find_min(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// Delete a key from the AVL tree
Node* delete(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = find_min(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}
// Print the tree (in-order traversal)
void print_tree(Node* root, int space) {
    if (!root) return;

    space += 5;

    print_tree(root->right, space);
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    print_tree(root->left, space);
}

// Test the AVL Tree
int main() {
    Node* root = NULL;

    int values_to_insert[] = {10, 20, 30, 40, 50, 25};
    int values_to_delete[] = {50, 40, 30};

    printf("Inserting values:\n");
    for (int i = 0; i < 6; i++) {
        root = insert(root, values_to_insert[i]);
        printf("Tree after inserting %d:\n", values_to_insert[i]);
        print_tree(root, 0);
        printf("\n");
    }

    printf("Deleting values:\n");
    for (int i = 0; i < 3; i++) {
        root = delete(root, values_to_delete[i]);
        printf("Tree after deleting %d:\n", values_to_delete[i]);
        print_tree(root, 0);
        printf("");
    }

    return 0;
}
