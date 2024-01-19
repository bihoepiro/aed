//
// Created by bihonda on 18/01/2024.
//

#ifndef HW_HT_HASH_TABLE_SET_H
#define HW_HT_HASH_TABLE_SET_H

#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

const int maxColision = 3;
const float maxFillFactor = 0.5;

template<typename TK, typename TV>
class Hash_Table_Set {
private:
    struct Entry {
        TK first;
        TV second;

        Entry(TK key, TV value) : first(key), second(value) {}
    };

    std::forward_list<Entry>* array;
    size_t capacity;
    size_t size;

    double computeBounds() const {
        return static_cast<double>(size) / (capacity * maxColision);
    }

    size_t hash(TK key) const {
        std::hash<TK> ptrHash;
        return ptrHash(key);
    }

    void resize() {
        auto oldArray = array;
        auto oldCapacity = capacity;
        capacity *= 2;
        array = new std::forward_list<Entry>[capacity];
        size = 0;

        for (int i = 0; i < static_cast<int>(oldCapacity); ++i) {
            for (const auto& it : oldArray[i]) {
                insert(it.first, it.second);
            }
        }

        delete[] oldArray;
    }

public:
    Hash_Table_Set() : capacity(10), array(new std::forward_list<Entry>[capacity]), size(0) {}

    std::forward_list<Entry>& iter(size_t index) {
        return array[index];
    }

    void build(std::initializer_list<std::pair<TK, TV>> values) {
        for (const auto& pair : values) {
            insert(pair.first, pair.second);
        }
    }

    void insert(TK key, TV value) {
        if (computeBounds() >= maxFillFactor) {
            resize();
        }
        size_t hashcode = hash(key);
        int index = hashcode % capacity;

        for (auto& it : array[index]) {
            if (it.first == key) {
                it.second = value;
                return;
            }
        }

        array[index].push_front(Entry(key, value));
        size++;
    }

    TV& find(TK key) const {
        size_t hashcode = hash(key);
        int index = hashcode % capacity;
        for (const auto& it : array[index]) {
            if (it.first == key) {
                return static_cast<std::basic_string<char> &>(static_cast<std::basic_string<char> &>(it.second));
            }
        }
        throw std::out_of_range("Key not found");
    }

    void remove(TK key) {
        size_t hashcode = hash(key);
        int index = hashcode % capacity;

        auto prev = array[index].before_begin();
        for (auto it = array[index].begin(); it != array[index].end(); ++it) {
            if (it->first == key) {
                array[index].erase_after(prev);
                size--;
                return;
            }
            prev++;
        }
    }

    Entry& find_min() const {
        if (size == 0) {
            throw std::out_of_range("Empty set");
        }

        auto minEntry = &array[0].front();
        for (size_t i = 1; i < capacity; ++i) {
            if (!array[i].empty() && array[i].front().first < minEntry->first) {
                minEntry = &array[i].front();
            }
        }

        return *minEntry;
    }

    Entry& find_max() const {
        if (size == 0) {
            throw std::out_of_range("Empty set");
        }

        auto maxEntry = &array[0].front();
        for (size_t i = 1; i < capacity; ++i) {
            if (!array[i].empty() && array[i].front().first > maxEntry->first) {
                maxEntry = &array[i].front();
            }
        }

        return *maxEntry;
    }

    Entry& find_next(TK key) const {
        for (size_t i = 0; i < capacity; ++i) {
            for (auto& entry : array[i]) {
                if (entry.first > key) {
                    return entry;
                }
            }
        }

        throw std::out_of_range("No next element");
    }

    Entry& find_prev(TK key) const {
        Entry* prevEntry = nullptr;

        for (size_t i = 0; i < capacity; ++i) {
            for (auto& entry : array[i]) {
                if (entry.first < key && (!prevEntry || entry.first > prevEntry->first)) {
                    prevEntry = &entry;
                }
            }
        }

        if (!prevEntry) {
            throw std::out_of_range("No previous element");
        }

        return *prevEntry;
    }

    std::forward_list<Entry> iter_order() const {
        std::forward_list<Entry> result;
        for (size_t i = 0; i < capacity; ++i) {
            for (const auto& entry : array[i]) {
                result.push_front(entry);
            }
        }
        return result;
    }

    size_t len() const {
        return size;
    }

    ~Hash_Table_Set() {
        delete[] array;
    }
};

#endif //HW_HT_HASH_TABLE_SET_H
