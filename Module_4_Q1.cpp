#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

int main() {
    Node *root = new Node{10, nullptr, nullptr};
    root->left = new Node{5, nullptr, nullptr};
    root->right = new Node{15, nullptr, nullptr};

    cout << "Root: " << root->data << endl;
    if (root->left != nullptr) {
        cout << "Left child: " << root->left->data << endl;
    } else {
        cout << "Left child: NULL" << endl;
    }
    if (root->right != nullptr) {
        cout << "Right child: " << root->right->data << endl;
    } else {
        cout << "Right child: NULL" << endl;
    }

    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
