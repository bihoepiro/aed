#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Caso CERO: Lista vacía o 1 nodo.
        if (head == nullptr || head->next == nullptr) {
            return head; //
        }

        // Demás casos:
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Imprime la lista (para verificar que el code funciona)
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Ejemplo 1: Un solo nodo de medio
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    std::cout << "Lista 1: ";
    printList(head1);
    // Comprobando que funcione el code
    ListNode *middle1 = solution.middleNode(head1);
    std::cout << "Nodo(s) del medio en Lista 1: ";
    printList(middle1);

    // Liberar memoria
    ListNode *current = head1;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    std::cout << std::endl;

    // Ejemplo 2: Dos nodos de medio
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    std::cout << "Lista 2: ";
    printList(head2);
    // Comprobando que funcione el code
    ListNode *middle2 = solution.middleNode(head2);
    std::cout << "Nodo(s) del medio en Lista 2: ";
    printList(middle2);

    // Liberar memoria
    current = head2;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
