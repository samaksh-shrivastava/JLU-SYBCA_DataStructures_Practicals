#include <iostream>
using namespace std;
#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int value) {
        if (isFull()) cout << "Stack is Full\n";
        else arr[++top] = value;
    }
    void pop() {
        if (isEmpty()) cout << "Stack is Empty\n";
        else top--;
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == SIZE - 1; }
};

int main() {
    Stack s;
    cout << (s.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << (s.isFull() ? "Stack is Full\n" : "Stack is not Full\n");
    return 0;
}
