//      1 Solution -> (1) is correct

//      2 Solution -> (2) is Correct

//      3 Solution

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtIndex(int val, int idx) {
        if (idx == 0) {
            insertHead(val);
        } else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; i < idx - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Index out of bounds" << endl;
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                if (newNode->next == nullptr) {
                    tail = newNode;
                }
            }
        }
    }

    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void deleteTail() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }

    void deleteAtIndex(int idx) {
        if (idx == 0) {
            deleteHead();
        } else {
            Node* temp = head;
            for (int i = 0; i < idx - 1 && temp != nullptr; ++i) {
                temp = temp->next;
            }
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Index out of bounds" << endl;
            } else {
                Node* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                if (temp->next == nullptr) {
                    tail = temp;
                }
            }
        }
    }

    int get(int idx) {
        Node* temp = head;
        for (int i = 0; i < idx && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            throw out_of_range("Index out of range");
        }
        return temp->data;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insertHead(1);
    ll.display();
    ll.insertTail(2);
    ll.display();
    ll.insertAtIndex(3, 1); // Insert 3 at index 1
    ll.display(); // Should display: 1 3 2

    cout << "Element at index 2: " << ll.get(2) << endl; // Should display: 2

    ll.deleteAtIndex(1); // Delete element at index 1
    ll.display(); // Should display: 1 2

    ll.deleteHead(); // Delete from head
    ll.display(); // Should display: 2

    ll.deleteTail(); // Delete from tail
    ll.display(); // Should display: (empty list)

    return 0;
}
