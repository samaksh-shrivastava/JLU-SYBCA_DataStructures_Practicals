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

Node* insertNode(Node *root, int value) {
    if (root == nullptr) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

Node* searchNode(Node *root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchNode(root->left, key);
    return searchNode(root->right, key);
}

int main() {
    Node *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    int key;
    cin >> key;
    Node *result = searchNode(root, key);
    if (result != nullptr) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    return 0;
}
