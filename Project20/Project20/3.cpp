#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    int size;
    int capacity;

public:
    Array(int initialSize = 0, int grow = 1) : head(nullptr), size(0), capacity(initialSize) {
        for (int i = 0; i < initialSize; ++i) {
            append(T());  // Initialize with default values
        }
    }

    ~Array() {
        clear();
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int GetSize() const {
        return size;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            capacity = size;
        }
    }

    void RemoveAll() {
        clear();
        size = 0;
        capacity = 0;
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
        ++size;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= size) throw out_of_range("Index out of bounds!");
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    void SetAt(int index, T value) {
        if (index < 0 || index >= size) throw out_of_range("Index out of bounds!");
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        temp->data = value;
    }

    T& operator[](int index) {
        return GetAt(index);
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            clear();
            Node* temp = other.head;
            while (temp) {
                append(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    void InsertAt(int index, T value) {
        if (index < 0 || index > size) throw out_of_range("Index out of bounds!");
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
        ++size;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) throw out_of_range("Index out of bounds!");
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        delete temp;
        --size;
    }

    void Print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
