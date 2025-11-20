#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int value) {
    Node *node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int height(Node *root) {
    if (root == nullptr) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh) return lh + 1;
    return rh + 1;
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout << height(root) << endl;
    return 0;
}
