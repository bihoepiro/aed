#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void push_front(const int& val, ListNode*& heady) {
    ListNode *newNode = new ListNode(val);
    newNode->next = heady;
    heady = newNode;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;

        int count = 0;

        ListNode *temp = head;
        while(temp){
            count += 1;
            temp = temp->next;
        }

        temp=head;

        for (int i=0; i < count; ++i){
            push_front(temp->val, prev);
            temp=temp->next;
        }

        return prev;
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
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    std::cout << "Lista original 1: ";
    printList(head1);
    // Comprobando que funcione el code
    ListNode *reversed1 = solution.reverseList(head1);
    std::cout << "Lista invertida 1: ";
    printList(reversed1);

    // Liberar memoria
    ListNode *current = reversed1;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    std::cout << std::endl;

    // Ejemplo 2
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);

    std::cout << "Lista original 2: ";
    printList(head2);
    // Comprobando que funcione el code
    ListNode *reversed2 = solution.reverseList(head2);
    std::cout << "Lista invertida 2: ";
    printList(reversed2);

    // Liberar memoria
    current = reversed2;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}