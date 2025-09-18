#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << value << " enqueued into queue." << endl;
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
        } else {
            cout << arr[front++] << " dequeued from queue." << endl;
        }
    }

    void displayFrontRear() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
            cout << "Rear element: " << arr[rear] << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.displayFrontRear();

    q.dequeue();
    q.displayFrontRear();

    q.dequeue();
    q.dequeue();
    q.displayFrontRear();

    return 0;
}
