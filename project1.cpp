#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void append(T val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void insert(T val, int position) {
        if (position < 0) {
            position = 0;
        }
        if (position > size) {
            position = size;
        }

        Node* newNode = new Node(val);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void remove(int position) {
        if (position < 0 || position >= size) {
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }

        size--;
    }

    void reverse() {
        if (size <= 1) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void print() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    int getSize() {
        return size;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

int main() {
    LinkedList<int> myList;
    myList.append(10);
    myList.append(20);
    myList.append(30);

    std::cout << " The Original List: ";
    myList.print();

    myList.insert(5, 0);
    myList.insert(25, 2);
    myList.insert(35, 6);

    std::cout << "List after inserting: ";
    myList.print();

    myList.remove(3);
    myList.remove(0);

    std::cout << "List after deleting: ";
    myList.print();

    myList.reverse();

    std::cout << "List after reversing: ";
    myList.print();

    std::cout << "List using subscript operator: ";
    for (int i = 0; i < myList.getSize(); i++) {
        std::cout << myList[i] << " -> ";
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}
