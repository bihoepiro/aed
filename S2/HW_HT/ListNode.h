//
// Created by bihonda on 18/01/2024.
//

#ifndef HW_HT_LISTNODE_H
#define HW_HT_LISTNODE_H

using namespace std;
// FORWARD LIST
template <typename T>
class ListNode {
public:
    T value;
    ListNode* next;
    ListNode(const T& val) : value(val), next(nullptr) {}
};

#endif //HW_HT_LISTNODE_H
