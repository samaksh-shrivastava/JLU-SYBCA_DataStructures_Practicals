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

int findMin(Node *root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

int findMax(Node *root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
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
    cout << "Min: " << findMin(root) << endl;
    cout << "Max: " << findMax(root) << endl;
    return 0;
}
