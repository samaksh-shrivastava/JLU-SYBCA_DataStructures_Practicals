#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
};

int nodeHeight(Node *n) {
    if (n == nullptr) return 0;
    return n->height;
}

int getBalance(Node *n) {
    if (n == nullptr) return 0;
    return nodeHeight(n->left) - nodeHeight(n->right);
}

Node* newNode(int value) {
    Node *node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(nodeHeight(x->left), nodeHeight(x->right)) + 1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right)) + 1;
    return y;
}

void preorder(Node *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node *root = newNode(10);
    root->right = newNode(20);
    root->right->right = newNode(30);
    root->height = 2;
    root->right->height = 1;

    root = leftRotate(root);

    preorder(root);
    cout << endl;
    return 0;
}
