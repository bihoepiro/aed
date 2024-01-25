#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal_value = 0;
        int count = 0;

        ListNode *temp = head;
        while(temp){
            count += 1;
            temp = temp->next;
        }

        for (int i = count-1; i >=0; --i){
            decimal_value += head->val * (pow(2, i));
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