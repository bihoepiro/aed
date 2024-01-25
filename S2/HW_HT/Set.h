//
// Created by bihonda on 18/01/2024.
//



#ifndef HW_HT_SET_H
#define HW_HT_SET_H

#include "Hash_Table_Set.h"
template<typename T>
class Set {
private:
    Hash_Table_Set<T, bool> hashTable;

public:
    Set() {}

    void Insert(T data) {
        hashTable.insert(data, true);
    }

    bool Remove(T data) {
        try {
            hashTable.remove(data);
            return true;
        } catch (const std::out_of_range&) {
            return false;
        }
    }

    bool Contains(T data) {
        try {
            hashTable.find(data);
            return true;
        } catch (const std::out_of_range&) {
            return false;
        }
    }

    Set Union(const Set &other) {
        Set result;

        for (const auto& entry : hashTable.iter_order()) {
            result.Insert(entry.first);
        }


        for (const auto& entry : other.hashTable.iter_order()) {
            result.Insert(entry.first);
        }

        return result;
    }

    Set Intersect(const Set &other) {
        Set result;


        for (const auto& entry : hashTable.iter_order()) {

            if (other.Contains(entry.first)) {
                result.Insert(entry.first);
            }
        }

        return result;
    }

    Set Difference(const Set &other) {
        Set result;

        for (const auto& entry : hashTable.iter_order()) {
            if (!other.Contains(entry.first)) {
                result.Insert(entry.first);
            }
        }

        return result;
    }

    ~Set() {}
};

#endif //HW_HT_SET_H




