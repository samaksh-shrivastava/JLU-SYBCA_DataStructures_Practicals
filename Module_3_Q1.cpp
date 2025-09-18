#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void createList(int n) {
    Node *newNode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newNode = new Node;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displayList() {
    Node* temp = head;
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    createList(n);
    displayList();

    return 0;
}
