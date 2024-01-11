#include <iostream>
using namespace std;
//DOUBLY LINKED LIST
template <typename T>
class DoublyListNode {
public:
    T data;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    DoublyListNode<T>* head;
    DoublyListNode<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    T front() {
        if (empty()) {throw out_of_range("Lista vacía");}
        return head->data;
    }

    T back() {
        if (empty()) {throw out_of_range("Lista vacía");}
        return tail->data;
    }

    void push_front(const T& value) {
        DoublyListNode<T>* newNode = new DoublyListNode<T>(value);
        if (empty()) {head = tail = newNode;}
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(const T& value) {
        DoublyListNode<T>* newNode = new DoublyListNode<T>(value);
        if (empty()) {head = tail = newNode;}
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    T pop_front() {
        if (empty()) {throw out_of_range("Lista vacía");}

        T frontValue = head->data;
        DoublyListNode<T>* temp = head;

        if (head == tail) {head = tail = nullptr;}
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return frontValue;
    }

    T pop_back() {
        if (empty()) {throw out_of_range("Lista vacía");}

        T backValue = tail->data;
        DoublyListNode<T>* temp = tail;

        if (head == tail) {head = tail = nullptr;}
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        return backValue;
    }

    void insert(const T& value, int position) {
        if (position < 0) {throw out_of_range("Posición no válida");}

        if (position == 0) {push_front(value);} else {
            DoublyListNode<T>* newNode = new DoublyListNode<T>(value);
            DoublyListNode<T>* temp = head;

            for (int i = 0; i < position - 1 && temp != nullptr; ++i) {temp = temp->next;}

            if (temp != nullptr) {
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next != nullptr) {temp->next->prev = newNode;}
                temp->next = newNode;
            }
        }
    }

    void remove(int position) {
        if (position < 0) {throw out_of_range("Posición no válida");}

        if (position == 0) {pop_front();}
        else {
            DoublyListNode<T>* temp = head;

            for (int i = 0; i < position && temp != nullptr; ++i) {temp = temp->next;}

            if (temp != nullptr) {
                if (temp == tail) {
                    pop_back();
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                }
            }
        }
    }

    T operator[](int index) {
        if (index < 0) {throw out_of_range("Indice negativo");}

        DoublyListNode<T>* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {throw out_of_range("Indice no válido");}
        return temp->data;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        while (!empty()) {pop_front();}
    }

    void reverse() {
        DoublyListNode<T>* current = head;
        DoublyListNode<T>* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {head = temp->prev;}
    }
};

int main() {
    DoublyLinkedList<int> myList;

    myList.push_back(3);
    myList.push_back(1);
    myList.push_back(4);
    myList.push_back(1);
    myList.push_back(5);

    //Probando algunos métodos de DLL
    cout << "Lista: ";
    for (int i = 0; i < 5; ++i) {
        cout << myList[i] << " ";
    }

    myList.reverse();
    cout << "\nReversed List: ";
    for (int i = 0; i < 5; ++i) {
        cout << myList[i] << " ";
    }

    return 0;
}
