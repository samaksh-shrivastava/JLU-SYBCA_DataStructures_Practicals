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

Node* findMinNode(Node *root) {
    while (root != nullptr && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node *root, int key) {
    if (root == nullptr) return root;
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else {
            Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    root = deleteNode(root, key);
    inorder(root);
    cout << endl;
    return 0;
}
