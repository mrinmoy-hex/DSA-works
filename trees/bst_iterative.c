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



BstNode* insert(BstNode *root, int data) {
    if (root == NULL) {
        return getNewNode(data);    // return immediately
    }

    BstNode *curr = root;

    while (true) {
        if (data <= curr->data) {
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

int findMin(BstNode *root) {
    BstNode* curr = root;

    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    }

    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr->data;
}

int findMax(BstNode *root) {
    BstNode* curr = root;

    if (root == NULL) {
        printf("Error: Tree is empty.\n");
        return -1;
    }

    while (curr->right != NULL) {
        curr = curr->right;
    }

    return curr->data;
}

int height(BstNode* root) {
    if (root == NULL)   return -1;      // -1 for edges, use 0 if counting nodes 

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int depth(BstNode* root, int data) {
    if (root == NULL) {
        printf("Eroor: Empty tree.\n");
        return -1;
    }

    BstNode* curr = root;
    int depth = 0;

    while (curr != NULL) {
        if (curr->data == data)         return depth;
        else if (data <= curr->data)    curr = curr->left;
        else                            curr = curr->right;
        depth++;
    }

    printf("%d not found in tree.\n", data);
    return -1;
}

int main() {
    BstNode *root = NULL;

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


    printf("Height of tree: %d\n", height(root));
    printf("Depth of 40: %d\n", depth(root, 40));
    printf("Depth of 15: %d\n", depth(root, 15));
    printf("Depth of 10: %d\n", depth(root, 10));


    return 0;
}