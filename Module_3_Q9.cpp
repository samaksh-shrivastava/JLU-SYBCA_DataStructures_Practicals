#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* tail = nullptr;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (tail == nullptr) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    cout << value << " inserted at end.\n";
}

void deleteFromBeginning() {
    if (tail == nullptr) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    Node* head = tail->next;
    if (head == tail) {
        cout << head->data << " deleted.\n";
        delete head;
        tail = nullptr;
    } else {
        tail->next = head->next;
        cout << head->data << " deleted from beginning.\n";
        delet
