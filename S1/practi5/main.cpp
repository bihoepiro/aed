#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        while (head != nullptr) {
            if (visited.count(head) > 0) {
                // El nodo ya ha sido visitado, hay un ciclo.
                return true;
            }

            visited.insert(head);
            head = head->next;
        }

        // Si llegamos aquí, no hay ciclo en la lista.
        return false;
    }
};

int main() {
    Solution solution;

    // Ejemplo 1
    ListNode *head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;  // Ciclo conectando el último nodo al segundo
    cout << "Ejemplo 1: " << (solution.hasCycle(head1) ? "true" : "false") << endl;

    // Ejemplo 2
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;  // Ciclo conectando el último nodo al primero
    cout << "Ejemplo 2: " << (solution.hasCycle(head2) ? "true" : "false") << endl;

    // Ejemplo 3
    ListNode *head3 = new ListNode(1);
    cout << "Ejemplo 3: " << (solution.hasCycle(head3) ? "true" : "false") << endl;

    // Liberar memoria
    delete head1;
    delete head2;
    delete head3;

    return 0;
}

