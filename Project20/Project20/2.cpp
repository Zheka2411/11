#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void append(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    DoublyLinkedList<T>* clone() {
        DoublyLinkedList<T>* newList = new DoublyLinkedList<T>();
        Node* temp = head;
        while (temp) {
            newList->append(temp->data);
            temp = temp->next;
        }
        return newList;
    }

    DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& other) {
        DoublyLinkedList<T> result;
        Node* temp = head;
        while (temp) {
            result.append(temp->data);
            temp = temp->next;
        }
        temp = other.head;
        while (temp) {
            result.append(temp->data);
            temp = temp->next;
        }
        return result;
    }

    DoublyLinkedList<T> operator*(const DoublyLinkedList<T>& other) {
        DoublyLinkedList<T> result;
        Node* temp1 = head;
        while (temp1) {
            Node* temp2 = other.head;
            while (temp2) {
                if (temp1->data == temp2->data) {
                    result.append(temp1->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return result;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
