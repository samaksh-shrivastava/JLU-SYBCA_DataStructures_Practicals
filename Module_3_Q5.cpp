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

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << head->data << " deleted from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << temp->next->data << " deleted from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    displayList();

    deleteFromEnd();
    displayList();

    deleteFromEnd();
    deleteFromEnd();
    deleteFromEnd(); // extra delete check

    return 0;
}
