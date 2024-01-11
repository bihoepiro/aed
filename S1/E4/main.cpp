#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0); // Nodo de inicio fake
        ListNode *current = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy->next;
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

    // Ejemplo 1
    ListNode *lista1 = new ListNode(1);
    lista1->next = new ListNode(2);
    lista1->next->next = new ListNode(4);

    ListNode *lista2 = new ListNode(1);
    lista2->next = new ListNode(3);
    lista2->next->next = new ListNode(4);

    std::cout << "Lista 1: ";
    printList(lista1);
    std::cout << "Lista 2: ";
    printList(lista2);
    // Comprobando que el code funcione
    ListNode *mergedList1 = solution.mergeTwoLists(lista1, lista2);
    std::cout << "Lista fusionada: ";
    printList(mergedList1);

    // Liberar memoria
    ListNode *current = mergedList1;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

