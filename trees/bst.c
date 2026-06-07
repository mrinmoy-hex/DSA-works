#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Recursive approach
typedef struct BstNode {
    int data;
    struct BstNode* left;
    struct BstNode* right;
} BstNode;


BstNode *getNewNode(int data) {
    BstNode* newNode = malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

BstNode *root;
// void insert(BstNode **root, int data) {
//     if (*root == NULL) {
//         *root = getNewNode(data);
//     }
//     else if (data <= (*root)->data) {
        
//     }
// }
BstNode* insert(BstNode *root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

bool search(BstNode* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data)    return true;
    else if (data <= root->data)    return search(root->left, data);
    else return search(root->right, data);
}

int main() {

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);

    int key = 20;

    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);

    return 0;
}