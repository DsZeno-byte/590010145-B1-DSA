#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct Node **root, int data){
    struct Node *newNode = createNode(data);
    if (*root == NULL){
        *root = newNode;
        return;
    }
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    while (front < rear){
        struct Node *temp = queue[front++];
        if (temp->left == NULL)
        {
            temp->left = newNode;
            break;
        }
        else{
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL){
            temp->right = newNode;
            break;
        }
        else{
            queue[rear++] = temp->right;
        }
    }
}
void inOrderTraversal(struct Node *root){
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main(){
    struct Node *root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 8);
    insert(&root, 9);
    printf("In-order Binary Tree: ");
    inOrderTraversal(root);

    return 0;
}
