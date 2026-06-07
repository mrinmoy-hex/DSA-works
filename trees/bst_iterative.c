#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Iterative approach
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

BstNode* insert(BstNode *root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    }

    BstNode *curr = root;

    while (true) {
        if (data <= root->data) {
            if (curr->left == NULL) {
                curr->left = getNewNode(data);  // found the spot
                break;
            }
            curr = curr->left;                  // go left
        } 
        else {
            if (curr->right == NULL) {
                curr->right = getNewNode(data);
                break;
            }
            curr = curr->right;                 // go right 
        }
    }

    return root;    // 
}

bool search(BstNode* root, int data) {
    BstNode* curr = root;

    while (curr != NULL) {
        if (curr->data == data)              return true;
        else if (data <= curr->data)        curr = curr->left;
        else                                curr = curr->right; 
    }

    return false;
}


int main() {
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 40);


    int key = 20;

    if (search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);


    return 0;
}