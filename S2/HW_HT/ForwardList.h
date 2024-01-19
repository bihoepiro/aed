//
// Created by bihonda on 18/01/2024.
//

#ifndef HW_HT_FORWARDLIST_H
#define HW_HT_FORWARDLIST_H

#include "ListNode.h"
#include "iostream"
using namespace std;

template <typename T>
class ForwardList {
private:
    ListNode<T>* head;
public:
    ForwardList() : head(nullptr) {}

    ListNode<T>* begin() {
        return head;
    }

    ListNode<T>* end() {
        return nullptr; // O ajusta según lo que represente el final en tu implementación
    }


    T front() {
        if (empty()) {throw out_of_range("Lista vacía");}
        return head->value;
    }

    T back() {
        if (empty()) {throw out_of_range("Lista vacía");}

        ListNode<T>* temp = head;
        while (temp->next != nullptr) {temp = temp->next;}
        return temp->value;
    }

    void push_front(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (empty()) {head = newNode;}
        else {
            ListNode<T>* temp = head;
            while (temp->next != nullptr) {temp = temp->next;}
            temp->next = newNode;
        }
    }

    T pop_front() {
        if (empty()) {throw out_of_range("Lista vacía");}

        T frontValue = head->value;
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        return frontValue;
    }

    T pop_back() {
        if (empty()) {
            throw out_of_range("Lista vacía");
        }

        if (head->next == nullptr) {
            T backValue = head->value;
            delete head;
            head = nullptr;
            return backValue;
        }

        ListNode<T>* temp = head;
        while (temp->next->next != nullptr) {temp = temp->next;}

        T backValue = temp->next->value;
        delete temp->next;
        temp->next = nullptr;
        return backValue;
    }

    T operator[](int index) {
        if (index < 0) {throw out_of_range("Indice negativo");}

        ListNode<T>* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {temp = temp->next;}

        if (temp == nullptr) {throw out_of_range("Indice no funcional");}

        return temp->value;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (!empty()) {pop_front();}
    }

    void sort() {
        // BubbleSort
        for (ListNode<T>* i = head; i != nullptr; i = i->next) {
            for (ListNode<T>* j = i->next; j != nullptr; j = j->next) {
                if (i->value > j->value) {
                    // Intercambiar los valores de los nodos
                    T tempVal = i->value;
                    i->value = j->value;
                    j->value = tempVal;
                }
            }
        }
    }

    void reverse() {
        ListNode<T>* prev = nullptr;
        ListNode<T>* temp = head;
        ListNode<T>* next = nullptr;

        while (temp != nullptr) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        head = prev;
    }
};


#endif //HW_HT_FORWARDLIST_H
