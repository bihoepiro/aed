#include "iostream"

template <typename T>
struct FloatTrait {
    static constexpr bool isFloat = false;
};

template <>
struct FloatTrait<float> {
    static constexpr bool isFloat = true;
};

template <typename T>
struct IntegerTrait {
    static constexpr bool isInteger = false;
};

template <>
struct IntegerTrait<int> {
    static constexpr bool isInteger = true;
};

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T, typename Trait>
class SortedLinkedList {
private:
    ListNode<T>* head;

public:
    SortedLinkedList() : head(nullptr) {}

    void insert(const T& value) {
        ListNode<T>* newNode = new ListNode<T>(value);

        // Si la lista está vacía o el nuevo elemento debe ir al principio
        if (!head || Trait::isFloat && value > head->data || Trait::isInteger && value < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            ListNode<T>* current = head;

            // Buscar la posición de inserción
            while (current->next && (Trait::isFloat && value <= current->next->data || Trait::isInteger && value >= current->next->data)) {
                current = current->next;
            }

            // Insertar el nuevo nodo en la posición correcta
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void remove(const T& value) {
        ListNode<T>* current = head;
        ListNode<T>* prev = nullptr;

        // Buscar el nodo con el valor a eliminar
        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }

        // Si se encontró el valor, eliminar el nodo
        if (current) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }

            delete current;
        }
    }

    void display() const {
        ListNode<T>* current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

