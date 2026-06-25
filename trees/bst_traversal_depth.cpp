#include <iostream>

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int value)
        : data(value), left(nullptr), right(nullptr) {}
};


void destroyTree(BstNode* root) {
    if (root == nullptr) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);

    delete root;
}


BstNode* getNewNode(int data) {
    return new BstNode(data);
}

BstNode* insert(BstNode *root, int data) {
    if (root == nullptr) {
        return getNewNode(data);
    }

    BstNode *curr = root;

    while (true) {
        if (data <= curr->data) {
            if (curr->left == nullptr) {
                curr->left = getNewNode(data);  // found the spot
                break;
            }
            curr = curr->left;                  // go left
        } 
        else {
            if (curr->right == nullptr) {
                curr->right = getNewNode(data);
                break;
            }
            curr = curr->right;                 // go right 
        }
    }

    return root;
}

// Depth-wise traversal

void PreOrder(BstNode *root) {
    // base condition
    if (root == nullptr) return;

    std::cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BstNode *root) {
    if (root == nullptr) return;

    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(BstNode *root) {
    if (root == nullptr) return;

    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << " ";
}




int main() {
    BstNode *root = nullptr;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 40);

    std::cout << "Preorder traversal: ";
    PreOrder(root);
    std::cout << "\n";

    std::cout << "Inorder traversal: ";
    InOrder(root);
    std::cout << "\n";
    
    std::cout << "Preorder traversal: ";
    PreOrder(root);
    std::cout << "\n";


    destroyTree(root);
    return 0;
}
