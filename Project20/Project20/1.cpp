#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (back) {
            back->next = newNode;
            newNode->prev = back;
            back = newNode;
        }
        else {
            front = back = newNode;
        }
    }

    T dequeue() {
        if (isEmpty()) throw runtime_error("Queue is empty!");
        Node* temp = front;
        T value = temp->data;
        front = front->next;
        if (front) front->prev = nullptr;
        else back = nullptr;
        delete temp;
        return value;
    }

    T peek() const {
        if (isEmpty()) throw runtime_error("Queue is empty!");
        return front->data;
    }
};
