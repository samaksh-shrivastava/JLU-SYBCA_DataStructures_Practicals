#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchElement(int key) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << key << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << key << " not found in the list.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
