#include "iostream"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal_value = 0;

        while (head) {
            decimal_value = decimal_value * 2 + head->val;
            head = head->next;
        }

        return decimal_value;
    }
};

int main() {
    // Creación de la lista enlazada
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    // Comprobando que funcione el code
    Solution solution;
    int result = solution.getDecimalValue(head);

    std::cout << "Valor decimal: " << result << std::endl;

    // Liberar memoria
    ListNode *current = head;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
