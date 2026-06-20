/*
- Level Order Traversal Code

*/
#include <iostream>
#include <queue>


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


void levelOrder(BstNode* root) {
    if (root == nullptr) return;
    std::queue<BstNode*> Q;
    Q.push(root);

    // while there is atleast one discovered node
    while (!Q.empty()) {
        BstNode *current = Q.front();
        std::cout << current->data << " ";
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);
        Q.pop();    // removing the element at front
    }
}



int main() {

    BstNode *root = nullptr;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 40);

    levelOrder(root);

    destroyTree(root);
    return 0;
}